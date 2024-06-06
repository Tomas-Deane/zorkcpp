#ifndef INVENTORY_H
#define INVENTORY_H

#include <list>
#include <memory>
#include <string>
#include "item.h"

using namespace std;

class Inventory {
private:
    list<shared_ptr<Item>> items;

public:
    Inventory();
    Inventory(const std::string& itemNameToRemove, const Inventory& other); // Constructor to remove item
    const list<shared_ptr<Item>>& getItems() const;
    string getStringInvList(); // list all items as long string to remove logic from mainwindow class
    void addItem(shared_ptr<Item> toAdd);
    shared_ptr<Item> findItem(const string& itemName);
};

#endif // INVENTORY_H
