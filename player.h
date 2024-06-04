#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "edibleItem.h"
#include "useableitem.h"

class Player {
private:
    std::string name;
    int calories;
    float height;

public:
    Player(const std::string& newName, float height, int age, bool firstTimePlaying);

    // CPP Concept: Friends
    friend class GameLogic;

    void setCalories(int cal);
    int getCalories() const;
    const std::string& getName() const;

    void eatItem(EdibleItem& food);
    std::string useItem(UsableItem& item);


    void printStringByChar(const std::string& newName);
};

// Global variable store total calories
extern int TOTAL_CALORIES; // Global variable nearly always bad practice, just using concept

#endif // PLAYER_H
