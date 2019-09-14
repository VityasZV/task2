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

namespace modeling::request {
    class Request // task in queue
    {
    public:
        float time; // time of performing task without breaks
        ClientId client;
        Request(float time,
                ClientId client) : time(time), client(client){}
    };
    
    float get_req_time(ClientId source_num); // task duration
    float get_pause_time(ClientId source_num); // pause duration between tasks
    
}// namespace modeling::request


#endif /* request_hpp */
