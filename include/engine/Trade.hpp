//
// Created by Emmanuel_Leclercq on 02/01/2025.
//

#ifndef TRADE_HPP
#define TRADE_HPP

class Trade {
public:
    Trade(int id, int order_id, double price, int quantity)
        : id(id), order_id(order_id), price(price), quantity(quantity) {}

    int id;          // Trade ID
    int order_id;    // Associated order ID
    double price;    // Trade price
    int quantity;    // Trade quantity
};

#endif //TRADE_HPP
