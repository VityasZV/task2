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


namespace modeling::event {
    
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
        void processing() override;
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
        void processing() override;
    };
    
    class InitialEvent : public Event {
        std::shared_ptr<modeling::calendar::Calendar> monitor;
        std::shared_ptr<modeling::server::Server> server;
        friend class modeling::server::Server;
    public:
      
        InitialEvent(float time, EventType type,
                     std::shared_ptr<modeling::calendar::Calendar> monitor, std::shared_ptr<modeling::server::Server> server,
                     std::optional<ClientId> client = std::nullopt) : Event(time, type), monitor(monitor), server(server){}
        void processing() override;
    };
}// namespace modeling::event

#endif /* event_hpp */
