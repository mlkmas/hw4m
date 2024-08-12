#include "Computer.h"
#include <iostream>
#include "PeripheralDevice.h"

Computer::Computer(int price, const std::string& manufacturer, const std::string& cpu, bool isALaptop, int numOfPorts)
    : Item(price, manufacturer), cpu(cpu), isALaptop(isALaptop), numOfPorts(numOfPorts) {}

void Computer::setCpu(const std::string& cpu) {
    this->cpu = cpu;
}

void Computer::setIsALaptop(bool isALaptop) {
    this->isALaptop = isALaptop;
}

std::string Computer::getCpu() const {
    return cpu;
}

bool Computer::getIsALaptop() const {
    return isALaptop;
}

int Computer::getNumOfPorts() const {
    return numOfPorts;
}

bool Computer::connectDevice(PeripheralDevice* device) {
    if (connectedDevices.size() >= numOfPorts) {
        std::cerr << "Cannot connect device: No available USB ports.\n";
        return false;
    }
    for (const auto& connectedDevice : connectedDevices) {
        if (typeid(*connectedDevice) == typeid(*device)) {
            std::cerr << "Cannot connect device: Same type of device already connected.\n";
            return false;
        }
    }
    connectedDevices.push_back(device);
    if (usedPorts < numOfPorts) {
        ++usedPorts;
    }
    return true;
}

void Computer::disconnectDevice(PeripheralDevice* device) {
    auto it = std::find(connectedDevices.begin(), connectedDevices.end(), device);
    if (it != connectedDevices.end()) {
        connectedDevices.erase(it);
        if (usedPorts > 0) {
            --usedPorts;
        }
    }
}

void Computer::printConnected() const {
    std::cout << "There are " << connectedDevices.size() << " connections to id " << getId() << ": " << (std::string)(*this) << std::endl;
    for (const auto& device : connectedDevices) {
        std::cout << static_cast<std::string>(*device) << std::endl;
    }
}

Computer::operator std::string() const {
    return Item::operator std::string() + ", " + (isALaptop ? "Laptop" : "Desktop") + ", " + cpu;
}

Computer::~Computer() {
    for (auto& device : connectedDevices) {
        device->disconnect(); // Ensure each device disconnects from this computer
    }
   
}
int Computer::getAvailablePorts() const {
    return numOfPorts - usedPorts;
}
