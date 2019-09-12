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

#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <optional>
#include <string>



namespace event {
    
    class Event {//базовое событие в календаре
        float time;
        EventType type;   // тип события
        std::optional<ServerId> server;
        ClientId client; // дополнительные сведения о событии в зависимости от типа
    public:
        Event(float time,
              EventType type, ClientId client, const std::optional<ServerId> server = std::nullopt): time(time), type(type), client(client), server(server) {}
        virtual void processing() = 0;
    };
}// namespace event


#endif /* event_hpp */
