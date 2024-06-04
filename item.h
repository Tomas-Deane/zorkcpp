#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item // This is  an abstract class because it contains one pure virtual function
{
protected: // PROTECTED CONCEPT
    std::string name; // item name displayed on gui for items in room and in inventory if present

public:
    Item(const std::string& newName);

    virtual ~Item() = default;

    virtual const std::string getInfo() const;

    const std::string& getName() const;
    void setName(const std::string& newName);
};

#endif // ITEM_H
