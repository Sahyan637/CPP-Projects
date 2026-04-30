#pragma once
#include <vector>
#include "Item.h"

class Inventory {
private:
    std::vector<Item> items;

public:
    void addItem(const Item& item);
    void removeItem(int id);
    void updateQuantity(int id, int qty);
    void displayAll() const;
};