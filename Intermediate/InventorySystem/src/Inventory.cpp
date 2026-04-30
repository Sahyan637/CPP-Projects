#include <iostream>
#include "Inventory.h"

void Inventory::addItem(const Item& item) {
    items.push_back(item);
}

void Inventory::removeItem(int id) {
    for(auto it = items.begin(); it != items.end(); ++it) {
        if(it->getId() == id) {
            items.erase(it);
            std::cout << "Item removed.\n";
            return;
        }
    }
    std::cout << "Item not found.\n";
}

void Inventory::updateQuantity(int id, int qty) {
    for(auto& item : items) {
        if(item.getId() == id) {
            item.setQuantity(qty);
            std::cout << "Quantity updated\n";
            return;
        }
    }
    std::cout << "Item not found.\n";
}
void Inventory::displayAll() const {
    for(const auto& item : items) {
        item.display();
    }
};