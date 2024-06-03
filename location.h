#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <list>
#include "item.h"

class Location {
private:
    std::string name;
    std::string description; // Creative writing / storyline or whatever goes here.
                               //Better to use some kind of json file or dialogue class like i mentioned in another comment. This will suffice for now
    std::list<Location*> exits; // list of exits from this location, Index 0 is North Exit, 1 is South Exit, 2 is East, 3 West
    std::list<Item> items; // list of items displayed on gui in itemLabel. removed from this list when taken to inventory
    std::string imagePath; // put image into the images folder in this project directory. Image path should be like: ":/images/myimg.png"

public:
    Location(const std::string& newName, const std::string& newDescription, const std::list<Location*>& newExits, const std::list<Item>& newItems, const std::string& newImagePath);
    // Lengthy constructor, consider using set/add methods to define the variables at different times for easier reading

    Location* moveLoc(int exit); // Return true if move successful, false if invalid move (value at exit index equal null pointer)

    void addItem(const Item& newItem); // probably should make addItem method that takes list of items and concatenates with existing items
    void removeItem(const std::string& itemName);
    const Item* getItem(const std::string& itemName) const; // get item by name

    void setExits(const std::list<Location*>& newExits);

    const std::string& getName() const;
    const std::string& getDescription() const;
    const std::list<Location*>& getExits() const;
    const std::list<Item>& getItems() const;
    const std::string& getImagePath() const;

    std::string getStringItemList(); // List all items in the location as 1 long string.
                                    //This is used to pass to mainwindow.cpp to remove as much game logic as possible from that class
};

#endif // LOCATION_H
