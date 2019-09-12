//
//  event.hpp
//  task2
//
//  Created by Виктор Задябин on 12/09/2019.
//  Copyright © 2019 Виктор Задябин. All rights reserved.
//

#ifndef event_hpp
#define event_hpp

#include "../enums.hpp"
#include "../request/request.hpp"
#include "../calendar/calendar.hpp"
#include "../server/server.hpp"

#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <optional>
#include <string>
#include <list>
#include <iostream>

namespace modeling {
    
namespace event {
    
    class FinishEvent : public Event{
        std::shared_ptr<modeling::server::Server> server;
        ClientId client;
        std::shared_ptr<modeling::calendar::Calendar> monitor;
        friend class modeling::server::Server;
    public:
        FinishEvent(float finish_time, EventType type,
                    ClientId client,
                    std::shared_ptr<modeling::calendar::Calendar> monitor, std::shared_ptr<modeling::server::Server> server) :
                    Event(finish_time, type), client(client), server(server),
                    monitor(monitor){}
        void processing() override {
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
    };
    
    class RequestEvent : public Event {
        //State server_state;
        ClientId client;
        //ServerId server_id;
        std::shared_ptr<modeling::server::Server> server;
        std::shared_ptr<modeling::calendar::Calendar> monitor;
        friend class modeling::server::Server;
    public:
        RequestEvent(float time, EventType type, ClientId client, std::shared_ptr<modeling::calendar::Calendar> monitor, std::shared_ptr<modeling::server::Server> server): Event(time, type), client(client), monitor(monitor), server(server){}
        void processing() override{
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
    };
    
    class InitialEvent : public Event {
        std::shared_ptr<modeling::calendar::Calendar> monitor;
        std::shared_ptr<modeling::server::Server> server;
        friend class modeling::server::Server;
    public:
      
        InitialEvent(float time, EventType type,
                     std::shared_ptr<modeling::calendar::Calendar> monitor, std::shared_ptr<modeling::server::Server> server, std::optional<ClientId> client = std::nullopt) : Event(time, type), monitor(monitor), server(server){}
        void processing() override{
            monitor->put(std::make_shared<RequestEvent>(time, EventType::Request, ClientId::First, monitor, server));
            monitor->put(std::make_shared<RequestEvent>(time, EventType::Request, ClientId::Second, monitor, server));
        }
    };
}// namespace modeling::event

}//modeling


#endif /* event_hpp */
