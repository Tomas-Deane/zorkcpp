#include "EdibleItem.h"
#include "negativecalorieexception.h"

EdibleItem::EdibleItem(const std::string& newName, int newCalContent)
    : Item(newName), calContent(newCalContent) {
    if (newCalContent <= 0) {
        throw NegativeCalorieException();
    }
}

void EdibleItem::setCalContent(int newCal) {
    calContent = newCal;
}

int EdibleItem::getCalContent() const {
    return calContent;
}

const std::string EdibleItem::getInfo() const {
    return name + " (" + std::to_string(calContent) + " kcal)";
}
