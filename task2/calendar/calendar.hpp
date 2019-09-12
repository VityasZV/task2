//
//  calendar.hpp
//  task2
//
//  Created by Виктор Задябин on 12/09/2019.
//  Copyright © 2019 Виктор Задябин. All rights reserved.
//

#ifndef calendar_hpp
#define calendar_hpp

#include "../enums.hpp"

#include <list>

namespace modeling{

namespace event {
    class Event {//базовое событие в календаре
        //        std::optional<ServerId> server;
        //        ClientId client; // дополнительные сведения о событии в зависимости от типа
    public:
        EventType type;   // тип события
        const float time;
        Event(float time, EventType type): time(time), type(type) {}
        virtual void processing() = 0;
        virtual ~Event() = default;
    };
}
namespace calendar{
    class Calendar: public std::list<std::shared_ptr<modeling::event::Event>> // календарь событий
    {
    public:
        void put (std::shared_ptr<modeling::event::Event> &&ev); // вставить событие в список с упорядочением по полю time (c cемантикой перемещения
        void put (const std::shared_ptr<modeling::event::Event> &ev);
        std::optional<std::shared_ptr<event::Event>> get(); // извлечь первое событие из календаря (с наименьшим модельным временем)
    };
}
    
}// namespace modeling::calendar

#endif /* calendar_hpp */
