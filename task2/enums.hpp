//
//  enums.hpp
//  task2
//
//  Created by Виктор Задябин on 12/09/2019.
//  Copyright © 2019 Виктор Задябин. All rights reserved.
//

#ifndef enums_hpp
#define enums_hpp

enum class EventType {
    Initialization = 1,
    Request,
    Finish,
};

enum class State {
    Run = 1,
    Idle = 0,
    Limit = 1000,
};

enum class ServerId {
    First,
    Second
};

enum class ClientId {
    None,
    First,
    Second
};

#endif /* enums_hpp */
