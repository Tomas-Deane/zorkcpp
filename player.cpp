#include "Player.h"
#include "print_namespace.h"
#include <iostream>
using namespace print_space;
int TOTAL_CALORIES = 0;

Player::Player(const std::string& newName, float newHeight, int newAge, bool newFirstTimePlaying) {
    this->name = newName;

    print("A player is being created with the following information!"); // using namespace print_space. namespace I made to abstract printing process some more, similar to pythons print

    printStringByChar(newName);

    union playerInfo { // Union used to print some player information while only storing 1 variable at a time.
        float height;
        int age;
        bool firstTimePlaying;
    };
    playerInfo player1;
    player1.age=newAge;
    std::cout << "Age : " << player1.age << std::endl;
    player1.age=newHeight;
    std::cout << "Height : " << player1.height << std::endl;
    player1.firstTimePlaying=newFirstTimePlaying;
    std::cout << "First Time Playing this game? : " << player1.firstTimePlaying  << "\nAll 3 of these variables came from this location in memory:" << &player1.firstTimePlaying << std::endl;

}

void Player::printStringByChar(const std::string& newName) { // POINTERS AND ARRAYS CONCEPT

    const size_t stringLength = newName.length(); // get length


    const char* namePtr = newName.c_str(); // set char pointer to first char in string

    // go through each character and print it
    for (size_t i = 0; i < stringLength; ++i) {
        std::cout << *namePtr << std::endl;  // print current char
        namePtr++;  // increment pointer to point to next char
    }
}


void Player::setCalories(int calories) { // still using setter for game logic
    this->calories = calories;
    TOTAL_CALORIES = calories; // Update global total
}

int Player::getCalories() const {
    return this->calories;
}

const std::string& Player::getName() const {
    return this->name;
}

void Player::eatItem(EdibleItem& food) {
    TOTAL_CALORIES += food.getCalContent();
    cout << "Object " << food.getName() << " was eaten." << endl;
    delete &food;
}

std::string Player::useItem(UsableItem& item) {
    std::string output = item.getName() + " was used: " + item.getUseDescription();
    delete &item;
    return output;
}
