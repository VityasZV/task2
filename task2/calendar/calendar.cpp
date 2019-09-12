//
//  calendar.cpp
//  task2
//
//  Created by Виктор Задябин on 12/09/2019.
//  Copyright © 2019 Виктор Задябин. All rights reserved.
//

#include "calendar.hpp"

namespace calendar {
    void Calendar::put(std::shared_ptr<event::Event> &&ev)
    {
        if( empty() ){ emplace_back(ev); return; }
        auto i = begin();
        while((i != end()) && ((*i)->time <= ev->time))
        {
            ++i;
        }
        insert(i, ev);
    }
    std::shared_ptr<event::Event> Calendar::get()
    {
        if(empty()) return NULL;
        auto last = front();
        pop_front();
        return last;
    }
    
    void Calendar::put(const std::shared_ptr<event::Event> &ev) {
        if( empty() ){ push_back(ev); return; }
        auto i = begin();
        while((i != end()) && ((*i)->time <= ev->time))
        {
            ++i;
        }
        insert(i, ev);
    }
    
    
}
