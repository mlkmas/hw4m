#pragma once
#include "Item.h"
#include <vector>
#include <string>
#include <stdexcept>
#include <utility> // For std::pair

class Branch {
private:
    std::vector<Item*> catalog;
    std::string location;
    const int capacity;

public:
    Branch(const std::string& location, int capacity);
    Branch(const Branch& other); // Copy constructor

    void addItem(Item* newItem);
    Item* removeItem(int id);
    Item* giveMeFinest(Item* itemType) const;

    const std::vector<Item*>& getCatalog() const;  // Now returns a vector reference
    std::string getLocation() const;
    Item* const* getCatalog(int& numItems) const;

    // Declare operator== (but don't define it here)
    bool operator==(const Branch& other) const;

    ~Branch();

    // Exception classes
    class ExistingItemError : public std::runtime_error {
    public:
        ExistingItemError() : std::runtime_error("Item with this ID already exists in the catalog") {}
    };

    class FullCatalogError : public std::runtime_error {
    public:
        FullCatalogError() : std::runtime_error("Branch catalog is full") {}
    };

    class NonExistingItemError : public std::runtime_error {
    public:
        NonExistingItemError() : std::runtime_error("Item with this ID does not exist in the catalog") {}
    };

    class NoneExistingItemTypeError : public std::runtime_error {
    public:
        NoneExistingItemTypeError() : std::runtime_error("No item of the given type exists in the catalog") {}
    };
};

// Declare the operator== for std::pair<std::string, Branch>
bool operator==(const std::pair<std::string, Branch>& lhs, const std::pair<std::string, Branch>& rhs);