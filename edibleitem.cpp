#include "EdibleItem.h"
#include "negativecalorieexception.h"

EdibleItem::EdibleItem(const std::string& newName,int newCalContent)
    : Item(newName) {
    if (newCalContent <= 0) {
        NegativeCalorieException e;
        throw e;
    }
}


void EdibleItem::setCalContent(int newCal) {
    calContent = newCal;
}

int EdibleItem::getCalContent() const {
    return calContent;
}

std::string EdibleItem::getName() const {
    return Item::name;
}

const std::string EdibleItem::getInfo() const {
    return name + " (" + std::to_string(calContent) + " kcal)";
}

