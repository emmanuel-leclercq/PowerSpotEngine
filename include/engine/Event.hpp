//
// Created by Emmanuel_Leclercq on 02/01/2025.
//

#ifndef EVENT_HPP
#define EVENT_HPP
#include <string>
#include <memory>

enum class EventType {
    MarketEvent,
    OrderEvent,
    TradeEvent,
    PortfolioEvent,
    Other
};

class Event {
public:
    Event(EventType type, const std::string& details)
        : type(type), details(details) {}

    EventType type;
    std::string details;
};

#endif //EVENT_HPP
