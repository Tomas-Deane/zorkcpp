#ifndef EDIBLEINVENTORY_H
#define EDIBLEINVENTORY_H
#include "inventory.h"
#include "EdibleItem.h"

class EdibleInventory {

private:
    list<EdibleItem> items;

public:
    EdibleInventory();

    EdibleInventory(const std::string& itemNameToRemove, const EdibleInventory& other); // This is a COPY CONSTRUCTOR that removes the item with name matching to input string

    const list<EdibleItem>& getItems() const;
    string getStringInvList(); // List all items in the location as 1 long string.
        //This is used to pass to mainwindow.cpp to remove as much game logic as possible from that class

    void addItem(const EdibleItem& toAdd);
    void removeItem(const EdibleItem& toRemove);

    EdibleItem* findItem(const string& itemName);
};

#endif // EDIBLEINVENTORY_H
