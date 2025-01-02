//
// Created by Emmanuel_Leclercq on 02/01/2025.
//

#include "ExampleStrategy.hpp"
#include "engine/OrderManager.hpp"
#include "include/engine/Event.hpp"
#include "
#include <iostream>

ExampleStrategy::ExampleStrategy(OrderManager& order_manager)
    : order_manager_(order_manager) {}

void ExampleStrategy::on_event(const std::shared_ptr<Event>& event) {
    if (event->type == EventType::MarketEvent) {
        std::cout << "Reacting to market event." << std::endl;
        static int order_id = 1;
        order_manager_.submit_order(order_id++, 100.0, 10); // Example logic
    }
}