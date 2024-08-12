#include "PeripheralDevice.h"
#include"Computer.h"
#include <iostream>
#include <typeinfo>

PeripheralDevice::PeripheralDevice(int price, const std::string& manufacturer, const std::string& color, bool isWireless)
    : Item(price, manufacturer), color(color), isWireless(isWireless), connectedComputer(nullptr) {}

std::string PeripheralDevice::getColor() const {
    return color;
}

bool PeripheralDevice::getIsWireless() const {
    return isWireless;
}

void PeripheralDevice::setColor(const std::string& color) {
    this->color = color;
}

void PeripheralDevice::setIsWireless(bool isWireless) {
    this->isWireless = isWireless;
}


class AlreadyConnectedError : public std::runtime_error {
public:
    AlreadyConnectedError() : std::runtime_error("Peripheral device is already connected") {}
};

class NoAvailablePortsError : public std::runtime_error {
public:
    NoAvailablePortsError() : std::runtime_error("No available ports to connect the device") {}
};

// Assuming you have a method that connects a device to a computer
bool PeripheralDevice::connectToDevice(Computer& computer) {
    if (connectedComputer) {
        throw AlreadyConnectedError();
    }

    if (computer.getAvailablePorts() <= 0) {
        throw NoAvailablePortsError();
    }

    connectedComputer = &computer;
    return true;
}

void PeripheralDevice::disconnect() {
    if (connectedComputer != nullptr) {
        connectedComputer->disconnectDevice(this);
        std::cout << static_cast<std::string>(*this) + " is disconnected from computer: " + static_cast<std::string>(*connectedComputer) << std::endl;
        connectedComputer = nullptr;
    }
}

PeripheralDevice::operator std::string() const {
    return Item::operator std::string() + ", " + (isWireless ? "Wireless" : "Wired") + ", " + color;
}

PeripheralDevice::~PeripheralDevice() {
    if (connectedComputer != nullptr) {
        disconnect();
    }
}
