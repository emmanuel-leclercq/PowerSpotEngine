//
// Created by Emmanuel_Leclercq on 02/01/2025.
//

#ifndef MARKETSIMULATOR_HPP
#define MARKETSIMULATOR_HPP

#include <random>
#include <memory>
#include "EventQueue.hpp"


class MarketEvent : public Event {
public:
    double price;

    explicit MarketEvent(double price) : price(price) {
    }
};

class MarketSimulator {
public:
    explicit MarketSimulator(EventQueue &event_queue);

    void simulate_tick(); // Generate a market event

private:
    EventQueue &event_queue_;
    std::default_random_engine random_engine_;
    std::uniform_real_distribution<double> price_distribution_;
};


#endif //MARKETSIMULATOR_HPP
