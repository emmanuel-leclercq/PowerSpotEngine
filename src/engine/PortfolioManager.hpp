//
// Created by Emmanuel_Leclercq on 02/01/2025.
//

#ifndef PORTFOLIOMANAGER_HPP
#define PORTFOLIOMANAGER_HPP


#include <unordered_map>
#include "EventQueue.hpp"

// Represents a portfolio position
struct Position {
    int quantity = 0;
    double average_price = 0.0;

    void update(int trade_quantity, double trade_price);
};

class PortfolioManager {
public:
    explicit PortfolioManager(EventQueue &event_queue);

    // Handles events (e.g., execution events)
    void on_event(const std::shared_ptr<Event> &event);

    // Retrieve portfolio data
    const std::unordered_map<int, Position> &get_positions() const;

    double get_account_balance() const;

private:
    EventQueue &event_queue_;
    std::unordered_map<int, Position> positions_;
    double account_balance_ = 1000000.0; // Example starting balance
};


#endif //PORTFOLIOMANAGER_HPP
