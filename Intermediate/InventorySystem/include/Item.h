#pragma once
#include <string>

class Item {
private:
    int id;
    std::string name;
    int quantity;
    double price;

public:
    Item(int id, std::string name, int quantity, double price);

    int getId() const;
    std::string getName() const;
    int getQuantity() const;
    double getPrice() const;

    void setQuantity(int qty);
    void display() const;
};