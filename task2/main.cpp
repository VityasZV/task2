//
//  main.cpp
//  task2
//
//  Created by Виктор Задябин on 12/09/2019.
//  Copyright © 2019 Виктор Задябин. All rights reserved.
//

//#include "enums.hpp"
//#include "event/event.hpp"
#include "calendar/calendar.hpp"
#include "module_client_server/modeling.hpp"

#include <exception>
#include <iostream>

int main(int argc, char **argv )
{
    try {
        modeling::Modeling model_client_server;
        model_client_server.Start();
    }
    catch (const std::exception& ex){
        std::cout << ex.what();
    }
    return 0;
}
