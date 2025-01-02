//
// Created by Emmanuel_Leclercq on 02/01/2025.
//

#include <gtest/gtest.h>
#include <memory>
#include <thread>

#include "engine/EventQueue.hpp"

// Test Event class for testing purposes
class TestEvent : public Event {
public:
    explicit TestEvent(const int id) : id_(id) {
    }

    int id_;
};

// Test fixture for EventQueue
class EventQueueTest : public ::testing::Test {
protected:
    EventQueue queue;

    void SetUp() override {
        // Optional setup
    }

    void TearDown() override {
        // Optional cleanup
    }
};

TEST_F(EventQueueTest, PushAndPopEvent) {
    const auto event1 = std::make_shared<TestEvent>(1);
    const auto event2 = std::make_shared<TestEvent>(2);

    queue.push(event1);
    queue.push(event2);

    const auto popped_event1 = std::dynamic_pointer_cast<TestEvent>(queue.pop());
    ASSERT_NE(popped_event1, nullptr);
    EXPECT_EQ(popped_event1->id_, 1);

    const auto popped_event2 = std::dynamic_pointer_cast<TestEvent>(queue.pop());
    ASSERT_NE(popped_event2, nullptr);
    EXPECT_EQ(popped_event2->id_, 2);
}

TEST_F(EventQueueTest, PopBlocksOnEmptyQueue) {
    std::thread producer([this]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        const auto event = std::make_shared<TestEvent>(42);
        queue.push(event);
    });

    const auto popped_event = std::dynamic_pointer_cast<TestEvent>(queue.pop());
    ASSERT_NE(popped_event, nullptr);
    EXPECT_EQ(popped_event->id_, 42);

    producer.join();
}
