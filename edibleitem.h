#ifndef EDIBLEITEM_H
#define EDIBLEITEM_H

#include <string>
#include "Item.h"


using namespace std;

class EdibleItem : virtual public Item{
private:
    int calContent;

public:

    EdibleItem(const std::string& newName, int newCalContent);



    const std::string getInfo() const override;

    void setCalContent(int newCal);
    int getCalContent() const;
    std::string getName() const; // get the name from the base class
};

#endif // EDIBLEITEM_H
