//
//  server.hpp
//  task2
//
//  Created by Виктор Задябин on 12/09/2019.
//  Copyright © 2019 Виктор Задябин. All rights reserved.
//

#ifndef server_hpp
#define server_hpp

#include "../request/request.hpp"
#include "../calendar/calendar.hpp"

#include <stdio.h>
#include <list>

namespace modeling{
    
//pre declaration for mentioning as friend classes
//in Server
namespace event {
    class InitialEvent;
    class RequestEvent;
    class FinishEvent;
}// event
    
namespace server{
    using queue = std::list<std::shared_ptr<request::Request>>;
    class Server {
        queue request_order;
        float working_start;
        ServerId server_id = ServerId::First;
        State server_state = State::Idle;
        friend class modeling::event::InitialEvent;
        friend class modeling::event::RequestEvent;
        friend class modeling::event::FinishEvent;
    public:
        Server(float working_start = 0) : working_start(working_start){};
    };
}// server
    
}// modeling
#endif /* server_hpp */
