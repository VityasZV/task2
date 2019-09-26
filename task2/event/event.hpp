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
#include "../dependencies/dependencies.hpp"


namespace modeling::event {
    
    class FinishEvent : public Event{
        ClientId client;
        const modeling::dependencies::Dependencies& dependencies;
    public:
        FinishEvent(float finish_time,
                    ClientId client,
                    const modeling::dependencies::Dependencies& dependencies) :
                    Event(finish_time), client(client), dependencies(dependencies){
                        type = EventType::Finish;
                    }
        void processing() override;
        ~FinishEvent() = default;
    };
    
    class RequestEvent : public Event {
        ClientId client;
        const modeling::dependencies::Dependencies& dependencies;
    public:
        RequestEvent(float time, ClientId client,
                     const modeling::dependencies::Dependencies& dependencies):
                        Event(time), client(client), dependencies(dependencies){
                            type = EventType::Request;
                        }
        void processing() override;
        ~RequestEvent() = default;
    };
    
    class InitialEvent : public Event {
        const modeling::dependencies::Dependencies& dependencies;
    public:
        InitialEvent(float time,
                     const modeling::dependencies::Dependencies& dependencies,
                     std::optional<ClientId> client = std::nullopt) :
                        Event(time), dependencies(dependencies){
                            type = EventType::Initialization;
                        }
        void processing() override;
        ~InitialEvent() = default;
    };
    
}// namespace modeling::event

#endif /* event_hpp */
