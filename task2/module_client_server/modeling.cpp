//
//  modeling.cpp
//  task2
//
//  Created by Виктор Задябин on 12/09/2019.
//  Copyright © 2019 Виктор Задябин. All rights reserved.
//

#include "modeling.hpp"

#include <iostream>

namespace modeling {
    void Modeling::Start() {
        while ((current_event_opt = dependencies.monitor.get()).has_value()){
            const auto& current_event = *current_event_opt;
            std::cout << "time: " << current_event->time << " type: " << out_event.at(current_event->type);
            current_time = current_event->time;
            if (current_time > Limit) {
                std::cout << std::endl;
                break;
            }
            current_event->processing();
        }
    }
}// namespace modeling
