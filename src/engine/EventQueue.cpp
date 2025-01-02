//
// Created by Emmanuel_Leclercq on 02/01/2025.
//

#include "EventQueue.hpp"

void EventQueue::push(const std::shared_ptr<Event> &event) {
    std::lock_guard lock(mutex_);
    queue_.push(event);
    cv_.notify_one();
}

std::shared_ptr<Event> EventQueue::pop() {
    std::unique_lock lock(mutex_);
    cv_.wait(lock, [this] { return !queue_.empty(); });
    auto event = queue_.front();
    queue_.pop();
    return event;
}

bool EventQueue::empty() const {
    return queue_.empty(); // Leverage the STL queue's empty method
}