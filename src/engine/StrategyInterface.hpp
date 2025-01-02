//
// Created by Emmanuel_Leclercq on 02/01/2025.
//

#ifndef STRATEGYINTERFACE_HPP
#define STRATEGYINTERFACE_HPP

#include "EventQueue.hpp"

class StrategyInterface {
public:
    virtual ~StrategyInterface() = default;

    virtual void on_event(const std::shared_ptr<Event> &event) = 0;
};


#endif //STRATEGYINTERFACE_HPP
