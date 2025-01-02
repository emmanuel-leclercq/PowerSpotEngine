//
// Created by Emmanuel_Leclercq on 02/01/2025.
//

#include "OrderManager.hpp"
#include "MarketSimulator.hpp"
#include <iostream>

OrderManager::OrderManager(EventQueue &event_queue)
    : event_queue_(event_queue) {
}

void OrderManager::on_event(const std::shared_ptr<Event> &event) {
    if (const auto market_event = std::dynamic_pointer_cast<MarketEvent>(event)) {
        for (auto const &[order_id, order]: orders_) {
            if (market_event->price >= order.price) {
                std::cout << "Order " << order_id << " executed at " << market_event->price << std::endl;
                event_queue_.push(std::make_shared<ExecutionEvent>(order_id, market_event->price));
                orders_.erase(order_id);
                break;
            }
        }
    }
}

void OrderManager::submit_order(int order_id, double price, int quantity) {
    orders_.try_emplace(order_id, order_id, price, quantity);
    std::cout << "Submitted order " << order_id << ": " << quantity << " @ " << price << std::endl;
}
