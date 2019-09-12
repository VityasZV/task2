//
//  request.hpp
//  task2
//
//  Created by Виктор Задябин on 12/09/2019.
//  Copyright © 2019 Виктор Задябин. All rights reserved.
//

#ifndef request_hpp
#define request_hpp

#include "../enums.hpp"

#include <stdio.h>
#include <list>

namespace modeling::request {
    class Request // задание в очереди
    {
    public:
        float time; // время выполнения задания без прерываний
        ClientId client; // номер источника заданий (1 или 2)
        Request(float time,
                ClientId client) : time(time), client(client){}
    };
    
    float get_req_time(ClientId source_num); // длительность задания
    float get_pause_time(ClientId source_num); // длительность паузы между заданиями
    
}// namespace modeling::request


#endif /* request_hpp */
