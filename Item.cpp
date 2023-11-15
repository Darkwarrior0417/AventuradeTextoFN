#include "Item.h"

Item::Item(const std::string& name, const std::string& description, ItemType type)
    : name(name), description(description), type(type) {}

const std::string& Item::getName() const {
    return name;
}

const std::string& Item::getDescription() const {
    return description;
}

Item::ItemType Item::getType() const {
    return type;
}