#include "Tablet.h"
#include <iostream>

Tablet::Tablet(int price, const std::string& manufacturer, const std::string& color, const std::string& cpu, int screenSize)
    : Item(price, manufacturer),
    PeripheralDevice(price, manufacturer, color, true),
    Computer(price, manufacturer, cpu, false, 1),
    screenSize(screenSize) {
    // Always wireless and not a laptop, hence the last arguments are fixed
}
int Tablet::getScreenSize() const {
    return screenSize;
}

void Tablet::setScreenSize(int screenSize) {
    this->screenSize = screenSize;
}

Tablet::operator std::string() const {
    return "id " + std::to_string(Item::getId()) + ": " + Item::getManufacturer() + " " + std::to_string(Item::getPrice()) + "$, Wireless, " + PeripheralDevice::getColor() +
        ", Screen size: " + std::to_string(screenSize) + ", " + (Computer::getIsALaptop() ? "Laptop" : "Tablet") + ", " + Computer::getCpu();
}

void Tablet::connect(Computer& computer) {
    if (&computer == this) {
        std::cerr << "A tablet cannot connect to itself.\n";
        return;
    }

    PeripheralDevice::connect(computer);
}

Tablet::~Tablet() {
    disconnect();  // Ensure disconnection from any connected computer
}
