//
//  event.cpp
//  task2
//
//  Created by Виктор Задябин on 12/09/2019.
//  Copyright © 2019 Виктор Задябин. All rights reserved.
//

#include "event.hpp"

#include <iostream>

namespace modeling::event{
    
    void InitialEvent::processing() {
        monitor->put(std::make_shared<RequestEvent>(
        /*time =*/time,
        /*EventType =*/EventType::Request,
        /*ClientId =*/ClientId::First,
        /*modeling::calendar::Calendar =*/monitor,
        /*Server =*/server));
        monitor->put(std::make_shared<RequestEvent>(time, EventType::Request, ClientId::Second, monitor, server));
    }
    
    void FinishEvent::processing() {
        server->server_state = State::Idle;
        //выводим запись о рабочем интервале time=finish_time
        std::cout << "Работа сервера:" << out_server.at(server->server_id)<< " c " << server->working_start << " по " << time << " длит. " << time - server->working_start << std::endl;
        if (!server->request_order.empty()){
            const auto& request = server->request_order.front();
            server->request_order.pop_front();
            monitor->put(std::make_shared<FinishEvent>(time + request->time, type, request->client, monitor, server));
            server->working_start = time;
        }
    }
    
    void RequestEvent::processing() {
        const auto dt = modeling::request::get_req_time(client);
        std::cout << "dt " << dt << " " << out_client.at(client) << std::endl;
        if (server->server_state == State::Idle){
            server->server_state = State::Run;
            monitor->put(std::make_shared<FinishEvent>(time + dt, type, client, monitor, server));
            server->working_start = time;
        }
        else {
            server->request_order.emplace_back(std::make_shared<request::Request>(dt, client));
        }
        //planning for generation of next task
        monitor->put(std::make_shared<event::RequestEvent>(time + request::get_pause_time(client), type,
                                                           client, monitor, server));
    }
}
