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
    void initializeLocations();

    bool moveLocGL(int i);
    Location* getCurrentLocation();

    void addItemToInventory(const std::shared_ptr<Item>& newItem);
    void removeItemFromInventory(const std::string& itemName);
    bool takeItemFromLocation(const std::string& itemName);

    Inventory& getInventory();

    Player& getPlayer();


};

#endif // GAMELOGIC_H
