#include <iostream>
#include "Inventory.h"
#include "Logger.h"

int main() {
    Inventory inventory;
    int choice;

    Logger::log("Application started");

    do {
        std::cout << "\n1. Add Item\n2. Remove item\n3. Update Quantity\n4. Display Items\n5. Exit\n";
        std::cin >> choice;

        if(choice == 1) {
            int id, qty;
            double price;
            std::string name;

            std::cout << "Enter ID Name Qty Price: ";
            std::cin >> id >> name >> qty >> price;

            inventory.addItem(Item(id, name, qty, price));
        } else if (choice == 2) {
            int id;
            std::cout << "Enter ID: ";
            std:: cin >> id;
            inventory.removeItem(id);
        } else if (choice == 3) {
            int id, qty;
            std::cout << "Enter ID and new Qty: ";
            std::cin >> id >> qty;
            inventory.updateQuantity(id, qty);
        } else if (choice == 4) {
            inventory.displayAll();
        }
    } while(choice != 5);

    return 0;
}