#include "Player.h"

Player::Player(const std::string& newName) {
    this->name = newName;
    this->calories = 0;
}

void Player::setCalories(int cal) {
    this->calories = cal;
}

int Player::getCalories() const {
    return this->calories;
}

const std::string& Player::getName() const {
    return this->name;
}
