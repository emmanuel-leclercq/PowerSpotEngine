//
// Created by Emmanuel_Leclercq on 02/01/2025.
//

#include "MarketSimulator.hpp"
#include <iostream>

MarketSimulator::MarketSimulator(EventQueue &event_queue)
    : event_queue_(event_queue),
      random_engine_(std::random_device{}()),
      price_distribution_(50.0, 150.0) {
} // Prices between 50 and 150

void MarketSimulator::simulate_tick() {
    double price = price_distribution_(random_engine_);
    std::cout << "Simulated price: " << price << std::endl;
    event_queue_.push(std::make_shared<MarketEvent>(price));
}
