//
// Created by Emmanuel_Leclercq on 02/01/2025.
//

#ifndef ORDERMANAGER_HPP
#define ORDERMANAGER_HPP


#include <unordered_map>
#include "EventQueue.hpp"

class OrderEvent : public Event {
public:
    int order_id;
    double price;
    int quantity;

    OrderEvent(const int order_id, const double price, const int quantity)
        : order_id(order_id), price(price), quantity(quantity) {
    }
};

class ExecutionEvent : public Event {
public:
    int order_id;
    double execution_price;

    ExecutionEvent(const int order_id, const double execution_price)
        : order_id(order_id), execution_price(execution_price) {
    }
};

class OrderManager {
public:
    explicit OrderManager(EventQueue &event_queue);

    void on_event(const std::shared_ptr<Event> &event);

    void submit_order(int order_id, double price, int quantity);

private:
    EventQueue &event_queue_;
    std::unordered_map<int, OrderEvent> orders_;
};


#endif //ORDERMANAGER_HPP
