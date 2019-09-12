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
            current_time = 0;
            dt = 0;
            server = std::make_shared<modeling::server::Server>();
            monitor = std::make_shared<modeling::calendar::Calendar>();
            monitor->put(std::make_shared<event::InitialEvent>(/*time =*/0, /*type =*/EventType::Initialization, /*monitor =*/monitor, /*server =*/ server, /*client =*/ std::nullopt));
        }
        void Start();
    };
}

#endif /* modeling_hpp */
