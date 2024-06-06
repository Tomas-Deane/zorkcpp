#ifndef PLAYER_H
#define PLAYER_H

#include <memory>
#include <string>
#include "edibleItem.h"
#include "useableitem.h"

class Player {
private:
    std::string name;
    float height;

public:
    Player(const std::string& newName, float height, int age, bool firstTimePlaying);

    // CPP Concept: Friends
    friend class GameLogic;

    const std::string& getName() const;

    void eatItem(std::shared_ptr<EdibleItem> food);
    void useItem(std::shared_ptr<UsableItem> item);



    void printStringByChar(const std::string& newName);
};

// Global variable store total calories
extern int TOTAL_CALORIES; // Global variable nearly always bad practice, just using concept

#endif // PLAYER_H
