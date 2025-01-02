//
// Created by Emmanuel_Leclercq on 02/01/2025.
//
#include <gtest/gtest.h>
#include "engine/EventQueue.hpp"
#include "engine/MarketSimulator.hpp"

TEST(MarketSimulatorTest, GenerateMarketEvent) {
    EventQueue queue;
    MarketSimulator simulator(queue);

    simulator.simulate_tick();
    auto event = std::dynamic_pointer_cast<MarketEvent>(queue.pop());
    ASSERT_NE(event, nullptr);
    EXPECT_GE(event->price, 50.0);
    EXPECT_LE(event->price, 150.0);
}
