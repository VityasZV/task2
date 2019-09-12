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
        while ((current_event_opt = monitor->get()).has_value()){
            auto current_event = *current_event_opt;
            std::cout << "time: " << current_event->time << " type: " << out_event.at(current_event->type) << std::endl;
            current_time = current_event->time;
            if (current_time > Limit) break;
            current_event->processing();
        }
    }
}
