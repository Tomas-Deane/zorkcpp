#include "inventory.h"
using namespace std;

Inventory::Inventory() { // default constructor be grand for player, always starts with no items in inv
}

Inventory::Inventory(const std::string& itemNameToRemove, const Inventory& other) {
    for (const auto& item : other.getItems()) {
        if (item->getName() != itemNameToRemove) {
            items.push_back(item); // add items that don't match the name to remove
        }
    }
}

const list<shared_ptr<Item>>& Inventory::getItems() const {
    return items;
}

string Inventory::getStringInvList() { // List all items in the location as 1 long string.
    string itemNames; //This is used to pass to mainwindow.cpp to remove as much game logic as possible from that class
    for (const auto& temp : items) {
        if (temp->getInfo() != items.back()->getInfo()) { // if statement to remove trailing comma
            itemNames += temp->getInfo() + ", ";
        } else {
            itemNames += temp->getInfo();
        }
    }
    return itemNames;
}

void Inventory::addItem(shared_ptr<Item> toAdd) { // add item to inv
    items.push_back(toAdd);
}

shared_ptr<Item> Inventory::findItem(const string& itemName) {
    for (auto it = items.begin(); it != items.end(); ++it) { // auto allow compiler to get type of it based on return type of items.begin()
        if ((*it)->getName() == itemName) {
            return *it; // Return the shared pointer to the found item
        }
    }
    return nullptr;
}
