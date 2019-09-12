//
//  calendar.hpp
//  task2
//
//  Created by Виктор Задябин on 12/09/2019.
//  Copyright © 2019 Виктор Задябин. All rights reserved.
//

#ifndef calendar_hpp
#define calendar_hpp

#include <list>
#include "../event/event.hpp"
namespace calendar {
    class Calendar: public std::list<std::shared_ptr<event::Event>> // календарь событий
    {
    public:
        void put (std::shared_ptr<event::Event> &&ev); // вставить событие в список с упорядочением по полю time (c cемантикой перемещения
        void put (const std::shared_ptr<event::Event> &ev);
        std::shared_ptr<event::Event> get(); // извлечь первое событие из календаря (с наименьшим модельным временем)
    };
    
    
}

#endif /* calendar_hpp */
