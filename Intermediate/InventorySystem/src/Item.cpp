#include <iostream>
#include "Item.h"

Item::Item(int id, std::string name, int quantity, double price) : id(id), name(name), quantity(quantity), price(price) {}

int Item::getId() const { return id; }
std::string Item::getName() const { return name; }
int Item::getQuantity() const { return quantity; }
double Item::getPrice() const { return price; }

void Item::setQuantity(int qty) {
    quantity = qty;
}

void Item::display() const {
    std::cout << "ID: " << id << ", Name: " << name << ", Qty: " << quantity << ", Price: " << price << std::endl;
}