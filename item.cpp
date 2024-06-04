#include "item.h"

Item::Item(const std::string& newName)
    : name(newName) {
}

const std::string& Item::getName() const {
    return name;
}


void Item::setName(const std::string& newName) {
    name = newName;
}

const std::string Item::getInfo() const {
    return name;
}
