#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player // Player class is pretty dead for this version of the game. Will introduce calorie system and then it will be more important.
                // going to put calories as global variable for chris concepts
{
private:
    std::string name;
    int calories;

public:
    Player(const std::string& newName);

    void setCalories(int cal);
    int getCalories() const;
    const std::string& getName() const;
};

#endif // PLAYER_H
