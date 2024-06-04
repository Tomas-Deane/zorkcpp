#include "EdibleInventory.h"
using namespace std;

EdibleInventory::EdibleInventory() { // default constructor be grand for player, always starts with no items in inv
}

EdibleInventory::EdibleInventory(const std::string& itemNameToRemove, const EdibleInventory& other) { // Deep copy constructor that also removes all items with a given name
    for (const auto& item : other.getItems()) {
        if (item.getName() != itemNameToRemove) {
            items.push_back(item); // put in item if it doesn't match the name to remove
        }
    }
}

const list<EdibleItem>& EdibleInventory::getItems() const {
    return items;
}

string EdibleInventory::getStringInvList() {// List all items in the location as 1 long string.
    string itemNames;                  //This is used to pass to mainwindow.cpp to remove as much game logic as possible from that class
    for (const auto& temp : items) {
        if (temp.getInfo() != items.back().getInfo()) { // if statement to remove trailing comma
            itemNames += temp.getInfo() + ", ";
        } else {
            itemNames += temp.getInfo();
        }
    }
    return itemNames;
}

void EdibleInventory::addItem(const EdibleItem& toAdd) { // add item to inv
    items.push_back(toAdd);
}

EdibleItem* EdibleInventory::findItem(const string& itemName) { // CPP CONCEPTS REFERENCES EXAMPLE
    for (auto it = items.begin(); it != items.end(); ++it) { // auto allow compiler to get type of it based on return type of items.begin()
        if (it->getName() == itemName) {
            return &*it; // &*it: *it deferences the it variable to access the actual item object it points to. &*it gives us the memory address of that object which is returned as an item pointer
        } // Returning a reference to the item object avoids copying the entire item object which would waste memory and take a long time
    }
    return nullptr;
}
