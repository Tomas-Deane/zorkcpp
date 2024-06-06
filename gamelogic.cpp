#include "GameLogic.h"
#include <memory>
#include <iostream>
#include "edibleitem.h"
#include "useableitem.h"
#include "seed.h"

using namespace std;

GameLogic::GameLogic() : p1("Chris", 180.7, 19, true) {
    initializeLocations();
}

GameLogic::~GameLogic() {
    // loop through and delete locations
    for (auto loc : allLocations) {
        delete loc;
    }
}
void GameLogic::initializeLocations() {
    // arguments are :(String name, String desc, String imagePath)
    Location* locCave = new Location("Musty Cave", "You begin to arise from your slumber. You can faintly see shafts of light from the entrance \n illuminating a near object. A ravenous hunger overcomes you.", ":/images/cave.png");
    Location* locCaveEnt = new Location("Cave Entrance", "You climb on all fours to the exit of the cave, you feel weak and frail as if you've been withering away. \n The light nearly becomes blinding. You are excited to once again become the uncontested king of the forest. \n As you near the outside world somehting seems off, the air is warm and damp, unlike the cool and \n fresh Spring-time air you expected. At the mouth of the cave horror beseeches a thunderous growl from you. \n It is unmistakeably Fall. You've hibernated for nearly a full year. ", ":/images/cave_entrance.png");
    Location* locCaveAl = new Location("Alcove", "Your hunger is crippling, you never woke up this famished any year before... \n There are some strange fungi growing on the wall. Despite the dangers you feel \n like you can't stop yourself from eating.", ":/images/cave_alcove.png");
    Location* locForS = new Location("Forest Entrance", "The area around the cave is rocky and barren. There is no nourishment to be found here. \n You gaze endearingly into the depths of the forest. You hope there is prey inside. \n As you enter you can hear scurrying in all directions. The animals must have \n flourished while you were asleep all year, no apex predator present to cull the herds. \n You almost feel guilty for your hunger and their inevitable demise.", ":/images/forest_entrance.png");
    Location* locCaveOut = new Location("Cave Outskirts", "To most there is nothing of value in this area. To most it is bare. \n Most are wasting their time here. For Chris, a prime 1000oz Ribeye awaits.", ":/images/cave_outskirts.png");
    Location* locForMid = new Location("Deep Woodlands", "Despite the presence of other animals you are too sluggish to hunt. \n You can barely move. Without an easy target you may succumb to starvation at any moment. \n Now you see a beehive. This will suffice.", ":/images/deep_woodlands.png");
    Location* locForW = new Location("West Forest Border", "This place is ripe with berries, but that is hardly enough to sustain\n  you in your current form. No wonder there are such fruits present, the bees that survived all year long \n in you absense are crucial for the nurturing of the forest.", ":/images/west_forest_border.png");
    Location* locForE = new Location("East Forest Border", "Here you can barely sight humans through the foliage, \n they are chopping wood, preparing for the winter. Despite your salivation you know that \n bear hide is a valuable item for humans, especially when the cold sets. Its best to turn around, \n you might not have the energy to fight yet. (Calories needed: 35,000)", ":/images/east_forest_border.png");
    Location* locForHumans = new Location("Human Settlement", "The humans gather to oppose your approach. They are brandishing axes and spears.", ":/images/human_settlement.png");
    Location* locForN = new Location("North Forest Border", "Finally you are struck with good fortune. \n A wounded deer lies at the feet of a singular young boy. His eyes widen in fear when he sees you. \n He runs away. This slain game will rejuvinate you significantly.", ":/images/north_forest_border.png");


    allLocations = { locCave, locCaveEnt, locCaveAl, locForS, locCaveOut, locForMid, locForW, locForE, locForN }; // keep list of all locations for deconstructing


    // set the exits for every location. basically construct the map, useful to give the location variables specific names instead of loc1, loc2.
    //Useful to have map drawn out next to you to copy down
    //                      N          S          E          W
    locCave->setExits({ locCaveEnt, nullptr, locCaveAl, nullptr });
    locCaveEnt->setExits({ locForS, locCave, locCaveOut, nullptr });
    locCaveAl->setExits({ nullptr, nullptr, nullptr, locCave });
    locForS->setExits({ locForMid, locCaveEnt, locCaveOut, nullptr });
    locCaveOut->setExits({ nullptr, nullptr, nullptr, locForS });
    locForMid->setExits({ locForN, locForS, locForE, locForW });
    locForE->setExits({ nullptr, nullptr, locForHumans, locForMid });
    locForHumans->setExits({ nullptr, nullptr, nullptr, locForE});
    locForW->setExits({ nullptr, nullptr, locForMid, nullptr });
    locForN->setExits({ nullptr, locForMid, nullptr, nullptr });



    locCave->getInventory().addItem(make_shared<UsableItem>("Lantern", "The light from the lantern strongly illuminates the surrounding area"));
    locCaveEnt->getInventory().addItem(make_shared<EdibleItem>("Bat Droppings", 15));
    locCaveAl->getInventory().addItem(make_shared<EdibleItem>("Fungi", 400));
    locForS->getInventory().addItem(make_shared<Seed<int>>("Hazelnut Seed", 50, 25));

    if (p1.name == "Chris") { // Direct access to name varialbe due to friends concept
        locCaveOut->getInventory().addItem(make_shared<EdibleItem>("1000oz Ribeye Steak", 70000));
    }

    locForMid->getInventory().addItem(make_shared<EdibleItem>("Honey", 14000));
    locForMid->getInventory().addItem(make_shared<EdibleItem>("Royal Jelly", 2700));
    locForMid->getInventory().addItem(make_shared<EdibleItem>("Queen Bee", 1));
    locForMid->getInventory().addItem(make_shared<EdibleItem>("Bee Larvae", 150));

    locForE->getInventory().addItem(make_shared<EdibleItem>("Human Droppings", 50));
    locForE->getInventory().addItem(make_shared<Seed<std::string>>("Cnona", 50, "Handful"));
    locForW->getInventory().addItem(make_shared<EdibleItem>("Raspberries", 1300));
    locForN->getInventory().addItem(make_shared<EdibleItem>("Deer carcass", 30000));

    currentLoc = locCave;

    std::cout << "Locations initialized." << std::endl;
}

bool GameLogic::moveLocGL(int i) { // EXAMPLE OF MEMORY MANAGEMENT/POINTERS
    if (currentLoc->getName() == "Human Settlement") {
        if (TOTAL_CALORIES >= 35000) {
            currentLoc->setDescription("You have risen victorious against the encampment. You are once again the king of the forest. Congratulations.");
            return true;
        }else if (TOTAL_CALORIES < 35000) {
            currentLoc->setDescription("You attempt to crawl away but it is too late. The humans take advantage of your emaciated state and finish you with ease");
             return true;
        }
    }
    Location* temp; // create location pointer known as temp on the stack
    temp = currentLoc; // value of currentLoc is a memory address. Temp and currentLoc now point to the same memory addresses, or to the same existing location object
    currentLoc = currentLoc->moveLoc(i); // attempt to update currentLoc
    if (temp == currentLoc){ // if no move made return false (invalid). Now check if they are still equal after the moveLoc call
        return false;
    } else {
        return true;        // else true
    }

}

Location* GameLogic::getCurrentLocation() {
    return currentLoc;
}

Inventory& GameLogic::getInventory() {
    return inv;
}


Player& GameLogic::getPlayer() { // dead code right now, should add features like asking player name and using player name in dialogue.
    return p1;
}



bool GameLogic::takeItemFromLocation(const std::string& itemName) {
    //find item using the shared pointer
    auto item = currentLoc->getInventory().findItem(itemName);
    if (item->getName() == itemName) {
        // put that item to the player's inventory
        inv.addItem(item);
        // Create a new inventory excluding the item by iterating through the current inventory
        Inventory newInv(itemName, currentLoc->getInventory()); // Create a new Inventory object on the stack
        currentLoc->getInventory() = newInv; // Assign the new object by copy
        return true;
    }
    return false;
}


