#include "Branch.h"
#include <typeinfo>
#include <algorithm>

Branch::Branch(const std::string& location, int capacity)
    : location(location), capacity(capacity) {}

Branch::Branch(const Branch& other)
    : location(other.location), capacity(other.capacity) {}

void Branch::addItem(Item* newItem) {
    if (catalog.size() >= capacity) {
        throw FullCatalogError();
    }
    for (auto item : catalog) {
        if (item->getId() == newItem->getId()) {
            throw ExistingItemError();
        }
    }
    catalog.push_back(newItem);
}

Item* Branch::removeItem(int id) {
    auto it = std::find_if(catalog.begin(), catalog.end(), [id](Item* item) {
        return item->getId() == id;
        });

    if (it == catalog.end()) {
        throw NonExistingItemError();
    }

    Item* removedItem = *it;
    catalog.erase(it);
    return removedItem;
}

Item* Branch::giveMeFinest(Item* itemType) const {
    Item* finestItem = nullptr;
    for (auto item : catalog) {
        if (typeid(*item) == typeid(*itemType)) {
            if (!finestItem || item->getPrice() > finestItem->getPrice()) {
                finestItem = item;
            }
        }
    }
    if (!finestItem) {
        throw NoneExistingItemTypeError();
    }
    return finestItem;
}

const std::vector<Item*>& Branch::getCatalog() const {
    return catalog;  // Return the vector reference
}

std::string Branch::getLocation() const {
    return location;
}

Branch::~Branch() {
    for (auto item : catalog) {
        delete item;
    }
}
