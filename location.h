#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <list>
#include <memory>
#include "Item.h"
#include "Inventory.h"
#include "edibleinventory.h"

class Location {
private:
    std::string name;
    std::string description;
    std::list<Location*> exits;
    Inventory locInv;
    EdibleInventory locEdInv;
    std::string imagePath;

public:
    Location(const std::string& newName, const std::string& newDescription, const std::string& newImagePath);

    Location* moveLoc(int exit);

    Inventory& getInventory();
    EdibleInventory& getEdInventory();

    void setExits(const std::list<Location*>& newExits);

    const std::string& getName() const;
    const std::string& getDescription() const;
    const std::list<Location*>& getExits() const;
    const std::list<std::shared_ptr<Item>>& getItems() const;
    const std::string& getImagePath() const;

};

#endif // LOCATION_H
