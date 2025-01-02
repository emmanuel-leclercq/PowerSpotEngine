//
// Created by Emmanuel_Leclercq on 02/01/2025.
//

#include "BacktestEngine.hpp"
#include <iostream>

BacktestEngine::BacktestEngine(std::shared_ptr<StrategyInterface> strategy, int ticks)
    : market_simulator_(event_queue_),
      order_manager_(event_queue_),
      portfolio_manager_(event_queue_),
      strategy_(strategy),
      ticks_(ticks) {
}

void BacktestEngine::run() {
    std::cout << "Starting backtest for " << ticks_ << " ticks." << std::endl;

    for (int i = 0; i < ticks_; ++i) {
        std::cout << "Tick " << i + 1 << ":" << std::endl;

        // Simulate a market tick
        market_simulator_.simulate_tick();

        // Process events in the queue
        while (!event_queue_.empty()) {
            auto event = event_queue_.pop();

            // Dispatch the event to the strategy
            strategy_->on_event(event);

            // Dispatch the event to other modules
            order_manager_.on_event(event);
            portfolio_manager_.on_event(event);
        }
    }

    // Display results
    std::cout << "Backtest complete.\nFinal Account Balance: "
            << portfolio_manager_.get_account_balance() << std::endl;
}
