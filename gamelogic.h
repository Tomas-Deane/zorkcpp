#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "location.h"
#include "inventory.h"
#include "player.h"

class GameLogic
{
private:
    Location* currentLoc;
    Inventory inv;
    Player p1; // P One (Player One), not P L

    std::list<Location*> allLocations; // list of all locations for deleting them to free memory

public:
    GameLogic();
    ~GameLogic(); // Destructor for making memory free
    bool moveLocGL(int i);
    void initializeLocations();
    void addItemToInventory(const Item& newItem);
    void removeItemFromInventory(const std::string& itemName);
    Location* getCurrentLocation();
    Inventory& getInventory();
    //Player& getPlayer();
    bool takeItemFromLocation(const std::string& itemName);
};

#endif // GAMELOGIC_H
