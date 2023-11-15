#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    enum class ItemType {
        KEY,
        WEAPON,

    };

    Item(const std::string& name, const std::string& description, ItemType type);

    const std::string& getName() const;
    const std::string& getDescription() const;
    ItemType getType() const;

private:
    std::string name;
    std::string description;
    ItemType type;
};

#endif // ITEM_H