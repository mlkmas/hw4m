#pragma once
#include <string>

class Item {
private:
    int price;
    std::string manufacturer;
    const int id;
    static int id_counter;

public:
    Item(int price, std::string manufacturer);
    Item();

    void setPrice(int price);
    void setManufacturer(const std::string& manufacturer);

    int getPrice() const;
    std::string getManufacturer() const;
    int getId() const;

    virtual operator std::string() const = 0;

    virtual ~Item();

    // Comparator function to sort items by id
    static bool itemPtrCompare(const Item* a, const Item* b) {
        return a->getId() < b->getId();
    }
};