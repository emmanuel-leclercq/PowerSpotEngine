//
// Created by Emmanuel_Leclercq on 02/01/2025.
//

#include <gtest/gtest.h>
#include "engine/BacktestEngine.hpp"
#include "engine/OrderManager.hpp"
#include "../examples/ExampleStrategy.hpp"


TEST(BacktestEngineTest, IntegrationTest) {
    std::shared_ptr<StrategyInterface> queue;
    const std::shared_ptr<StrategyInterface> &order_manager(queue);
    const std::shared_ptr<StrategyInterface> &strategy(order_manager);
    BacktestEngine engine(strategy, 5);
    engine.run();
    SUCCEED(); // If it runs without crashes, it's a success for now
}
