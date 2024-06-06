#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <list>
#include <memory>
#include "Item.h"
#include "Inventory.h"

class Location {
private:
    std::string name;
    std::string description;
    std::list<Location*> exits;
    Inventory locInv;
    std::string imagePath;

public:
    Location(const std::string& newName, const std::string& newDescription, const std::string& newImagePath);

    Location* moveLoc(int exit);

    Inventory& getInventory();

    void setExits(const std::list<Location*>& newExits);

    const std::string& getName() const;
    const std::string& getDescription() const;
    void setDescription(std::string desc);
    const std::list<Location*>& getExits() const;
    const std::list<std::shared_ptr<Item>>& getItems() const;
    const std::string& getImagePath() const;

};

#endif // LOCATION_H
