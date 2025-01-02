//
// Created by Emmanuel_Leclercq on 02/01/2025.
//

#include "PortfolioManager.hpp"
#include "OrderManager.hpp"
#include <iostream>

void Position::update(const int trade_quantity, const double trade_price) {
    double total_cost = average_price * quantity + trade_price * trade_quantity;
    quantity += trade_quantity;
    if (quantity != 0) {
        average_price = total_cost / quantity;
    } else {
        average_price = 0.0; // Reset if position is closed
    }
}

PortfolioManager::PortfolioManager(EventQueue& event_queue)
    : event_queue_(event_queue) {}

void PortfolioManager::on_event(const std::shared_ptr<Event>& event) {
    if (auto exec_event = std::dynamic_pointer_cast<ExecutionEvent>(event)) {
        std::cout << "Processing execution event for order " << exec_event->order_id
                  << " at price " << exec_event->execution_price << std::endl;

        int trade_quantity = 10; // Example fixed quantity for demonstration
        double trade_price = exec_event->execution_price;

        // Update positions
        auto& position = positions_[exec_event->order_id];
        position.update(trade_quantity, trade_price);

        // Update account balance
        account_balance_ -= trade_quantity * trade_price;
    }
}

const std::unordered_map<int, Position>& PortfolioManager::get_positions() const {
    return positions_;
}

double PortfolioManager::get_account_balance() const {
    return account_balance_;
}
