#include "inventory.h"

Inventory::Inventory() { // default constructor be grand here, game always starts with no items in inv
}

const std::list<Item>& Inventory::getItems() const {
    return items;
}

std::string Inventory::getStringInvList() {// List all items in the location as 1 long string.
    std::string itemNames;                  //This is used to pass to mainwindow.cpp to remove as much game logic as possible from that class
    for (const auto& temp : items) {
        itemNames += temp.getName() + ", "; // Will have trailing comma for now, FIX
    }
    return itemNames;
}

void Inventory::addItem(const Item& toAdd) { // add item to inv
    items.push_back(toAdd);
}


// void Inventory::removeItem(const std::string& itemName) { // right now no implementation for this. will quickly add eating/using items

// }
