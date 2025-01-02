//
// Created by Emmanuel_Leclercq on 02/01/2025.
//

#ifndef EXAMPLESTRATEGY_HPP
#define EXAMPLESTRATEGY_HPP

#include "engine/StrategyInterface.hpp"
#include "engine/OrderManager.hpp"


class ExampleStrategy : public StrategyInterface {
public:
    explicit ExampleStrategy(OrderManager& order_manager);
    void on_event(const std::shared_ptr<Event>& event) override;

private:
    OrderManager& order_manager_;
};



#endif //EXAMPLESTRATEGY_HPP
