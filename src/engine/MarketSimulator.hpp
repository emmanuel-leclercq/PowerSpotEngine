//
// Created by Emmanuel_Leclercq on 02/01/2025.
//

#ifndef MARKETSIMULATOR_HPP
#define MARKETSIMULATOR_HPP

#include "EventQueue.hpp"


class MarketSimulator {
public:
    explicit MarketSimulator(EventQueue &event_queue);

    void simulate_tick();

private:
    EventQueue &event_queue_;
};


#endif //MARKETSIMULATOR_HPP
