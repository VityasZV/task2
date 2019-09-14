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
    const auto& all_clients = [](){
        return std::vector<const ClientId>{ClientId::First, ClientId::Second, ClientId::Third};
    }();
    const auto& clients_and_ints =[](){
        struct clients_and_ints {
            std::unordered_map<const ClientId, const int> left {
                {ClientId::First, 1},
                {ClientId::Second, 2},
                {ClientId::Third, 3}
            };
            std::unordered_map<int, const ClientId> right {
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
        for (const auto& client : all_clients){
            dependencies.monitor.put(std::make_shared<RequestEvent>(
            /*time =*/time,
            /*EventType =*/EventType::Request,
            /*ClientId =*/client,
            /*dependencies =*/dependencies));
        }
    }
    
    void FinishEvent::processing() {
        dependencies.server.server_state = State::Idle;
        //выводим запись о рабочем интервале time=finish_time
        std::cout << "Работа сервера:" << out_server.at(dependencies.server.server_id)<< " c " << dependencies.server.working_start << " по " << time << " длит. " << time - dependencies.server.working_start << std::endl;
        if (!dependencies.server.request_order.empty()){
            const auto& request = dependencies.server.request_order.front();
            dependencies.server.request_order.pop_front();
            dependencies.monitor.put(std::make_shared<FinishEvent>(time + request->time, type, request->client, dependencies));
            dependencies.server.working_start = time;
        }
    }
    
    void RequestEvent::processing() {
        const auto dt = modeling::request::get_req_time(client);
        std::cout << "dt " << dt << " " << out_client.at(client) << std::endl;
        if (dependencies.server.server_state == State::Idle){
            dependencies.server.server_state = State::Run;
            dependencies.monitor.put(std::make_shared<FinishEvent>(time + dt, type, client, dependencies));
            dependencies.server.working_start = time;
        }
        else {
            dependencies.server.request_order.emplace_back(std::make_shared<request::Request>(dt, client));
        }
        //planning for generation of next task
        dependencies.monitor.put(std::make_shared<RequestEvent>(time + request::get_pause_time(Planning(client)), type,
                                                           client,dependencies));

    }
}
