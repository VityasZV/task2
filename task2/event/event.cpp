//
//  event.cpp
//  task2
//
//  Created by Виктор Задябин on 12/09/2019.
//  Copyright © 2019 Виктор Задябин. All rights reserved.
//

#include "event.hpp"

#include <iostream>
#include <vector>

namespace modeling::event{
    
namespace {

    void FromClientLogging (const ClientId& client){
        std::cout << ", from " << out_client.at(client) << std::endl;
    }

    const auto& all_clients = [](){
        return std::vector<ClientId>{ClientId::First, ClientId::Second, ClientId::Third};
    }();
    const auto& clients_and_ints =[](){// kind of boost::bimap
        struct clients_and_ints {
            const std::unordered_map<ClientId, int> left {
                {ClientId::First, 1},
                {ClientId::Second, 2},
                {ClientId::Third, 3}
            };
            const std::unordered_map<int, ClientId> right {
                {1, ClientId::First},
                {2, ClientId::Second},
                {3, ClientId::Third}
            };
        };
        clients_and_ints initializing;
        return initializing;
    }();
    ClientId Planning(ClientId working_client){
        return clients_and_ints.right.at(
                        clients_and_ints.left.at(working_client)%3 + 1);
    }
    
}// namespace
    
    void InitialEvent::processing() {
        std::cout << std::endl;
        for (const auto& client : all_clients){
            dependencies.monitor.put(std::make_shared<RequestEvent>(time + request::get_pause_time(client),
                                                                    client, dependencies));
        }
    }
    
    void FinishEvent::processing() {
        FromClientLogging(client);
        dependencies.server.server_state = State::Idle;
        //выводим запись о рабочем интервале time=finish_time
        std::cout << "Работа сервера:" << out_server.at(dependencies.server.server_id)<<
        " c " << dependencies.server.working_start << " по " << time << " длит. " <<
        time - dependencies.server.working_start << " from " <<out_client.at(client) << std::endl;
        if (!dependencies.server.request_order.empty()){
            const auto request = dependencies.server.request_order.front();
            dependencies.server.request_order.pop_front();
            dependencies.monitor.put(std::make_shared<FinishEvent>(time + request->time,
                                                                   request->client, dependencies));
        }
        dependencies.server.working_start = time;
    }
    
    void RequestEvent::processing() {
        FromClientLogging(client);
        const auto dt = modeling::request::get_req_time(client);
        std::cout << "dt " << dt << " " << out_client.at(client) << std::endl;
        if (dependencies.server.server_state == State::Idle){
            dependencies.server.server_state = State::Run;
            dependencies.monitor.put(std::make_shared<FinishEvent>(time + dt,
                                                                   client, dependencies));
            dependencies.server.working_start = time;
        }
        else {
            dependencies.server.request_order.emplace_back(std::make_shared<request::Request>(dt, client));
        }
        //planning for generation of next task
        const auto&& next_client = Planning(client);
        dependencies.monitor.put(std::make_shared<RequestEvent>(time + request::get_pause_time(next_client),
                                                                next_client,dependencies));
    }
}// namespace modeling::event
