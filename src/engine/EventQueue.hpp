//
// Created by Emmanuel_Leclercq on 02/01/2025.
//

#ifndef EVENTQUEUE_HPP
#define EVENTQUEUE_HPP

#include <queue>
#include <mutex>
#include <condition_variable>
#include <memory>

// Base Event class
struct Event {
    virtual ~Event() = default;
};


class EventQueue {
public:
    void push(const std::shared_ptr<Event> &event);
    bool empty() const;
    std::shared_ptr<Event> pop();

private:
    std::queue<std::shared_ptr<Event> > queue_;
    std::mutex mutex_;
    std::condition_variable cv_;
};


#endif //EVENTQUEUE_HPP
