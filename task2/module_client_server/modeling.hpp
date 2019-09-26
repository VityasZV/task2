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
#include "../dependencies/dependencies.hpp"

namespace modeling {
    class Modeling {
        const modeling::dependencies::Dependencies& dependencies;
        float current_time;
        float dt;
        std::optional<std::shared_ptr<modeling::event::Event>> current_event_opt;
    public:
        Modeling(const modeling::dependencies::Dependencies& dependencies) :
        dependencies(dependencies){
            srand(2019);
            current_time = 0;
            dt = 0;
            dependencies.monitor.put(std::make_shared<event::InitialEvent>(/*time =*/0, dependencies, /*client =*/ std::nullopt));
        }
        void Start();
    };
}// namespace modeling

#endif /* modeling_hpp */
