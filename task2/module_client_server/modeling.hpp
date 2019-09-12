//
//  modeling.hpp
//  task2
//
//  Created by Виктор Задябин on 12/09/2019.
//  Copyright © 2019 Виктор Задябин. All rights reserved.
//

#ifndef modeling_hpp
#define modeling_hpp

#include "../enums.hpp"
#include "../request/request.hpp"
#include "../calendar/calendar.hpp"
#include "../server/server.hpp"
#include "../event/event.hpp"

namespace modeling {
    class Modeling {
        std::shared_ptr<modeling::calendar::Calendar> monitor;
        std::shared_ptr<modeling::server::Server> server;
        float current_time;
        float dt;
        std::optional<std::shared_ptr<modeling::event::Event>> current_event_opt;
    public:
        Modeling() {
            srand(2019);
//            monitor.put(std::make_shared<event::Event>(event::Event(curr_time, EventType::Initialization, ClientId::None)))
           // monitor.put(std::make_shared<event::InitialEvent>())
            current_time = 0;
            dt = 0;
            server = std::make_shared<modeling::server::Server>();
            monitor = std::make_shared<modeling::calendar::Calendar>();
//            InitialEvent(float time, EventType type,
//            std::shared_ptr<modeling::calendar::Calendar> monitor, std::shared_ptr<modeling::server::Server> server, std::optional<ClientId> client = std::nullopt) : Event(time, type), monitor(monitor), server(server
            monitor->put(std::make_shared<event::InitialEvent>(/*time =*/0, /*type =*/EventType::Initialization, /*monitor =*/monitor, /*server =*/ server, /*client =*/ std::nullopt));
        }
        void Start() {
            while ((current_event_opt = monitor->get()).has_value()){
                auto current_event = *current_event_opt;
                std::cout << "time: " << current_event->time << " type: " << out_event.at(current_event->type) << std::endl;
                current_time = current_event->time;
                if (current_time > Limit) break;
                current_event->processing();
            }
        }
    };
}

#endif /* modeling_hpp */
