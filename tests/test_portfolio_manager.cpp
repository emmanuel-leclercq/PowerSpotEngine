//
// Created by Emmanuel_Leclercq on 02/01/2025.
//

#include <gtest/gtest.h>
#include "engine/EventQueue.hpp"
#include "engine/PortfolioManager.hpp"
#include "engine/OrderManager.hpp"

TEST(PortfolioManagerTest, UpdatePositionAndBalance) {
    EventQueue queue;
    PortfolioManager portfolio(queue);

    // Simulate an execution event
    auto exec_event = std::make_shared<ExecutionEvent>(1, 100.0); // Order ID 1, executed at $100
    portfolio.on_event(exec_event);

    const auto& positions = portfolio.get_positions();
    ASSERT_EQ(positions.size(), 1);
    EXPECT_EQ(positions.at(1).quantity, 10);
    EXPECT_EQ(positions.at(1).average_price, 100.0);

    EXPECT_EQ(portfolio.get_account_balance(), 1000000.0 - 10 * 100.0);
}

TEST(PortfolioManagerTest, ClosePosition) {
    EventQueue queue;
    PortfolioManager portfolio(queue);

    // Simulate opening and closing a position
    auto exec_event1 = std::make_shared<ExecutionEvent>(1, 100.0); // Buy
    portfolio.on_event(exec_event1);

    auto exec_event2 = std::make_shared<ExecutionEvent>(1, 105.0); // Sell
    portfolio.on_event(exec_event2);

    const auto& positions = portfolio.get_positions();
    EXPECT_EQ(positions.at(1).quantity, 0);
    EXPECT_EQ(positions.at(1).average_price, 0.0);

    EXPECT_EQ(portfolio.get_account_balance(), 1000000.0 - 10 * 100.0 + 10 * 105.0);
}