//
// Created by Emmanuel_Leclercq on 02/01/2025.
//

#ifndef BACKTEST_ENGINE_HPP
#define BACKTEST_ENGINE_HPP

#include "MarketSimulator.hpp"
#include "OrderManager.hpp"
#include "PortfolioManager.hpp"
#include "StrategyInterface.hpp"
#include "EventQueue.hpp"


class BacktestEngine {
public:
    BacktestEngine(std::shared_ptr<StrategyInterface> strategy, int ticks);

    void run();

private:
    EventQueue event_queue_;
    MarketSimulator market_simulator_;
    OrderManager order_manager_;
    PortfolioManager portfolio_manager_;
    std::shared_ptr<StrategyInterface> strategy_;
    int ticks_;
};

#endif // BACKTEST_ENGINE_HPP
