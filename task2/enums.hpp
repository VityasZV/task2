//
//  enums.hpp
//  task2
//
//  Created by Виктор Задябин on 12/09/2019.
//  Copyright © 2019 Виктор Задябин. All rights reserved.
//

#ifndef enums_hpp
#define enums_hpp

#include <unordered_map>
#include <string>

enum class EventType {
    Initialization = 1,
    Request,
    Finish,
};

enum class State {
    Idle,
    Run
};

enum class ServerId {
    First,
    Second
};

enum class ClientId {
    First,
    Second,
    Third
};

static const float Limit = 1000;

static const std::unordered_map<const ClientId, const std::string> out_client = {
    {ClientId::First, std::string("client:1")},
    {ClientId::Second, std::string("client:2")},
    {ClientId::Third, std::string("client:3")}
};

static const std::unordered_map<const ServerId, const std::string> out_server = {
    {ServerId::First, "First"},
    {ServerId::Second, "Second"},
};

static const std::unordered_map<EventType, const std::string> out_event = {
    {EventType::Initialization, std::string("Initialization")},
    {EventType::Request, std::string("Request")},
    {EventType::Finish, std::string("Finish")},
};

    

#endif /* enums_hpp */
