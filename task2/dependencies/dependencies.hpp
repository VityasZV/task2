//
//  dependencies.hpp
//  task2
//
//  Created by Виктор Задябин on 14/09/2019.
//  Copyright © 2019 Виктор Задябин. All rights reserved.
//

#ifndef dependencies_hpp
#define dependencies_hpp

#include "../calendar/calendar.hpp"
#include "../server/server.hpp"

#include <stdio.h>

namespace modeling::dependencies {
    struct Dependencies {
        modeling::calendar::Calendar& monitor;
        modeling::server::Server& server;
        Dependencies(modeling::calendar::Calendar& monitor,
                     modeling::server::Server& server):
        monitor(monitor), server(server){}
        
    };
}// modeling::dependencies

#endif /* dependencies_hpp */
