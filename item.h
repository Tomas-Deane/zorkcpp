#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item
{
private:
    std::string name; // item name displayed on gui for items in room and in inventory if present
    int calContent; // auto set to zero if unspecified

public:
    Item();
    Item(const std::string& newName, int newCalContent); //for inedible items set to negative num (nothing a bear couldnt eat, plenty bear cant digest)


    const std::string& getName() const;
    int getCalContent() const;

    void setName(const std::string& newName);
    void setCalContent(int newCalContent);
};

#endif // ITEM_H
