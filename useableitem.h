#ifndef USABLEITEM_H
#define USABLEITEM_H

#include "Item.h"

class UsableItem : virtual public Item {
private:
    std::string useDescription;

public:
    UsableItem(const std::string& newName, const std::string& newUseDescription);

    const std::string getInfo() const override; // Override getInfo method
    const std::string& getUseDescription() const;
};

#endif // USABLEITEM_H
