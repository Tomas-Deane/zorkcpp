#include "Location.h"

Location::Location(const std::string& newName, const std::string& newDescription, const std::string& newImagePath)
    : name(newName), description(newDescription), imagePath(newImagePath) {
}

Location* Location::moveLoc(int exit) {
    auto it = std::next(getExits().begin(), exit);
    if (it == getExits().end() || *it == nullptr) {
        return this;
    }
    return *it;
}

Inventory& Location::getInventory() {
    return locInv;
}

EdibleInventory& Location::getEdInventory() {
    return locEdInv;
}

void Location::setExits(const std::list<Location*>& newExits) {
    if (newExits.size() == 4) {
        exits = newExits;
    }
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

const std::string& Location::getImagePath() const {
    return imagePath;
}
