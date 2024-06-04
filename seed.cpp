#include "Seed.h"
#include <sstream>



template <typename T>
Seed<T>::Seed(const std::string& newName, int calories, T qty)
    : Item(newName), EdibleItem(newName, calories), UsableItem(newName, "You planted the " + newName + "."), quantity(qty) {}

template <typename T>
Seed<T>::Seed(const std::string& newName, T qty)
    : Item(newName), EdibleItem(newName, Default_Cal), UsableItem(newName, "You planted the " + newName + "."), quantity(qty) {}

template <typename T>
const std::string Seed<T>::getInfo() const {
    return getName() + "(" + std::to_string(getCalContent()) + "kcal) (" + getUseDescription() + ")x" + getQuantityStr();
}

template <typename T>
T Seed<T>::getQuantity() const {
    return quantity;
}

template <typename T>
std::string Seed<T>::getQuantityStr() const {
    std::ostringstream oss;
    oss << quantity;
    return oss.str();
}

// Explicit instantiation for common types
template class Seed<int>;
template class Seed<std::string>;
template class Seed<bool>;
