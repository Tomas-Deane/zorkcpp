#ifndef INVENTORY_H
#define INVENTORY_H

#include <list>
#include "item.h"

class Inventory
{
private:
    std::list<Item> items;

public:
    Inventory();

    const std::list<Item>& getItems() const;
    std::string getStringInvList(); // List all items in the location as 1 long string.
                                                //This is used to pass to mainwindow.cpp to remove as much game logic as possible from that class

    void addItem(const Item& toAdd);

    //void removeItem(const std::string& itemName);
};

#endif // INVENTORY_H
