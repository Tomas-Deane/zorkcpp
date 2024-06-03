#include "item.h"

Item::Item(const std::string& newName, int newCalContent = 0)
    : name(newName), calContent(newCalContent) { //for inedible items consider set calories to negative num (nothing a bear couldnt eat, plenty bear cant digest)
}

const std::string& Item::getName() const {
    return name;
}

int Item::getCalContent() const {
    return calContent;
}

void Item::setName(const std::string& newName) {
    name = newName;
}

void Item::setCalContent(int newCalContent) {
    calContent = newCalContent;
}

