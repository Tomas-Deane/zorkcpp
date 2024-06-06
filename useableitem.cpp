#include "useableItem.h"

UsableItem::UsableItem(const std::string& newName, const std::string& newUseDescription)
    : Item(newName), useDescription(newUseDescription) {
}

const std::string UsableItem::getInfo() const {
    return name + " (Usable)";
}

const std::string& UsableItem::getUseDescription() const {
    return useDescription;
}
