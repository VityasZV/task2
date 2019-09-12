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
//    class Event;
//    class InitialEvent;
//    class RequestEvent;
//    class FinishEvent;
    
    
    class FinishEvent : public Event{
        float working_start_of_server;
        ServerId server;
        State& server_state;
        ClientId client;
        modeling::calendar::Calendar& monitor;
        modeling::server::queue& queue_of_server;
        friend class modeling::server::Server;
    public:
        FinishEvent(float finish_time, EventType type,float working_start_of_server,
                    ClientId client, ServerId server,
                    State& server_state, modeling::calendar::Calendar& monitor,
                    modeling::server::queue& queue_of_server) :
                    Event(finish_time, type), client(client), server(server), server_state(server_state),
                    monitor(monitor), working_start_of_server(working_start_of_server),
                    queue_of_server(queue_of_server){}
        void processing() override {
            server_state = State::Idle;
            //выводим запись о рабочем интервале time=finish_time
             std::cout << "Работа сервера:" << out_server.at(server)<< " c " << working_start_of_server << " по " << time << " длит. " << time - working_start_of_server << std::endl;
            if (!queue_of_server.empty()){
                const auto& request = queue_of_server.front();
                queue_of_server.pop_front();
                // monitor.put(std::make_shared<FinishEvent>(time + request->time));
                working_start_of_server = time;
            }

//            if (curr_ev->server.value() == ServerId::First){
//                cpu_state_1=State::Idle;
//                // выводим запись о рабочем интервале
//                std::cout << "Работа сервера:" << out_server.at(curr_ev->server.value())<< " c " << run_begin_1 << " по " << curr_time << " длит. " << curr_time-run_begin_1 << std::endl;
//                if (!queue_1.empty())
//                {
//                    auto reqest_1 = queue_1.front();
//                    queue_1.pop_front();
//                    u_calendar.put(std::make_shared<event::Event>(curr_time + reqest_1->time, EventType::Finish, reqest_1->client, curr_ev->server));
//                    run_begin_1 = curr_time;
//                }
//            }
        }
    };
    
    class RequestEvent : public Event {
        State server_state;
        ClientId client;
        ServerId server_id;
        modeling::calendar::Calendar& monitor;
        friend class modeling::server::Server;
    public:
        RequestEvent(float time, EventType type, ClientId client, modeling::calendar::Calendar& monitor): Event(time, type), client(client), monitor(monitor){
            const auto dt = modeling::request::get_req_time(client);
            std::cout << "dt " << dt << " " << out_client.at(client) << std::endl;
            
            //monitor put finish
        }
        void processing() override{
            
        }
    };
    
    class InitialEvent : public Event {
        modeling::calendar::Calendar& monitor;
      //  std::optional<ClientId> client; //used to transfer for creating RequestEvent, or nothing
        friend class modeling::server::Server;
    public:
      
        InitialEvent(float time, EventType type,
                     modeling::calendar::Calendar& monitor, std::optional<ClientId> client = std::nullopt) : Event(time, type), monitor(monitor){
             monitor.put(std::make_shared<InitialEvent>(*this));
        }
        void processing() override{
            //(float time, EventType type, ClientId client, modeling::calendar::Calendar& monitor): Event(time, type), client(client), monitor(monitor)
            monitor.put(std::make_shared<RequestEvent>(time, type, ClientId::First, monitor));
            monitor.put(std::make_shared<RequestEvent>(time, type, ClientId::Second, monitor));
            //monitor.put(std::make_shared<RequestEvent>())
//            monitor.put(std::make_shared<event::Event>(curr_time, EventType::Request, ClientId::First));
//            monitor.put(std::make_shared<event::Event>(curr_time, EventType::Request, ClientId::Second))
//            calendar.put(new Event(curr_time, EV_REQ, 1));
//            calendar.put(new Event(curr_time, EV_REQ, 2));
        }
    };
}// namespace modeling::event

}//modeling


#endif /* event_hpp */
