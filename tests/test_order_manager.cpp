//
// Created by Emmanuel_Leclercq on 02/01/2025.
//
#include <gtest/gtest.h>
#include "engine/EventQueue.hpp"
#include "engine/OrderManager.hpp"
#include "engine/MarketSimulator.hpp"

TEST(OrderManagerTest, SubmitAndExecuteOrder) {
    EventQueue queue;
    OrderManager order_manager(queue);

    order_manager.submit_order(1, 100.0, 10);

    MarketSimulator simulator(queue);
    simulator.simulate_tick();

    order_manager.on_event(queue.pop());
    auto execution_event = std::dynamic_pointer_cast<ExecutionEvent>(queue.pop());
    ASSERT_NE(execution_event, nullptr);
    EXPECT_EQ(execution_event->order_id, 1);
    EXPECT_GE(execution_event->execution_price, 50.0);
    EXPECT_LE(execution_event->execution_price, 150.0);
}