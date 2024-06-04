#ifndef SEED_H
#define SEED_H

#include "EdibleItem.h"
#include "UseableItem.h"

//#define Default_Cal 10 // TOGGLE ADVANCED PREPROCESSOR DIRECTIVES

#ifndef Default_cal
#warning "Default Calories was not defined in Seed class"
#define Default_Cal 10
#endif

template <typename T>
class Seed : public EdibleItem, public UsableItem {
private:
    T quantity;

public:
    Seed(const std::string& newName, int calories, T qty);
    Seed(const std::string& newName, T qty);

    const std::string getInfo() const override;
    T getQuantity() const;
    std::string getQuantityStr() const;
};

#endif // SEED_H
