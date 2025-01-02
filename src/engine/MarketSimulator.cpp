//
// Created by Emmanuel_Leclercq on 02/01/2025.
//

#include "MarketSimulator.hpp"
#include <iostream>

MarketSimulator::MarketSimulator(EventQueue& event_queue)
    : event_queue_(event_queue) {}

void MarketSimulator::simulate_tick() {
    std::cout << "Simulating market tick..." << std::endl;
    // Add simulation logic here.
}