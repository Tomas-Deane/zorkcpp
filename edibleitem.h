#ifndef EDIBLEITEM_H
#define EDIBLEITEM_H

#include <string>
#include "Item.h"

using namespace std;

class EdibleItem : virtual public Item {
private:
    int calContent;

public:
    EdibleItem(const std::string& newName, int newCalContent);

    const std::string getInfo() const override;

    void setCalContent(int newCal);
    int getCalContent() const;
};

#endif // EDIBLEITEM_H
