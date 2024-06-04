#ifndef INVENTORY_H
#define INVENTORY_H
#include <list>
#include "item.h"

using namespace std;
class Inventory
{
private:
    list<Item> items;

public:
    Inventory();

    Inventory(const std::string& itemNameToRemove, const Inventory& other); // This is a COPY CONSTRUCTOR that removes the item with name matching to input string

    const list<Item>& getItems() const;
    string getStringInvList(); // List all items in the location as 1 long string.
                                                //This is used to pass to mainwindow.cpp to remove as much game logic as possible from that class

    void addItem(const Item& toAdd);
    void removeItem(const Item& toRemove);

    Item* findItem(const string& itemName);
};

#endif // INVENTORY_H
