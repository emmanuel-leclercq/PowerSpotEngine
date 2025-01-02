//
// Created by Emmanuel_Leclercq on 02/01/2025.
//

#ifndef ORDER_HPP
#define ORDER_HPP

enum class OrderType {
    Buy,
    Sell
};

class Order {
public:
    Order(int id, OrderType type, double price, int quantity)
        : id(id), type(type), price(price), quantity(quantity) {}

    int id;
    OrderType type;
    double price;
    int quantity;
};

#endif //ORDER_HPP
