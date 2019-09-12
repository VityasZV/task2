//
//  request.cpp
//  task2
//
//  Created by Виктор Задябин on 12/09/2019.
//  Copyright © 2019 Виктор Задябин. All rights reserved.
//

#include "request.hpp"

#include <iostream>

namespace modeling::request {
    static int rc = 0, pc = 0;
    float get_req_time(ClientId source_num)
    {
        // Для демонстрационных целей - выдаётся случайное значение
        // при детализации модели функцию можно доработать
        double r = ((double)rand())/RAND_MAX;
        std::cout << "req " << rc << std::endl; rc++;
        if(source_num == ClientId::First) return r*10; else return r*20;
    }
    
    float get_pause_time(ClientId source_num) // длительность паузы между заданиями
    {
        // см. комментарий выше
        double p = ((double)rand())/RAND_MAX;
        std::cout << "pause " << pc << std::endl; pc++;
        if(source_num == ClientId::First) return p*20; else return p*10;
    }
}// namespace request
