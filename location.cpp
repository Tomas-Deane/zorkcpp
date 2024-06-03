#include "location.h"

Location::Location(const std::string& newName, const std::string& newDescription, const std::list<Location*>& newExits, const std::list<Item>& newItems, const std::string& newImagePath)
    : name(newName), description(newDescription), items(newItems), imagePath(newImagePath)
{    // Lengthy constructor, consider using set/add methods to define the variables at different times for easier reading
    if (newExits.size() == 4) {
        exits = newExits;
    }
}

Location* Location::moveLoc(int exit) {
    auto it = std::next(getExits().begin(), exit); // next takes list and index, iterates through list until it reaches index, returns value at index
    if (it == getExits().end() || *it == nullptr) {
        return this;
    }
    return *it;
}

void Location::setExits(const std::list<Location*>& newExits) {
    if (newExits.size() == 4) {
        exits = newExits;
    }
}

void Location::addItem(const Item& newItem) {
    items.push_back(newItem);
}

void Location::removeItem(const std::string& itemName) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->getName() == itemName) {
            items.erase(it);
            return;
        }
    }
}

const Item* Location::getItem(const std::string& itemName) const {
    for (const auto& item : items) {
        if (item.getName() == itemName) {
            return &item;
        }
    }
    return nullptr;
}

std::string Location::getStringItemList() {// List all items in the location as 1 long string.
    std::string itemNames;                  //This is used to pass to mainwindow.cpp to remove as much game logic as possible from that class
    for (const auto& temp : items) {
        itemNames += temp.getName() + ", "; // Will have trailing comma for now, FIX
    }
    return itemNames;
}

const std::string& Location::getName() const {
    return name;
}

const std::string& Location::getDescription() const {
    return description;
}

const std::list<Location*>& Location::getExits() const {
    return exits;
}

const std::list<Item>& Location::getItems() const {
    return items;
}

const std::string& Location::getImagePath() const {
    return imagePath;
}
