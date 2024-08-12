#pragma once
#include "Item.h"
#include <vector>
#include <string>

// Forward declaration of PeripheralDevice class
class PeripheralDevice;

class Computer : public virtual  Item {
private:
    std::string cpu;
    bool isALaptop;
    const int numOfPorts;
    int usedPorts;
    std::vector<PeripheralDevice*> connectedDevices;

public:
    Computer(int price, const std::string& manufacturer, const std::string& cpu, bool isALaptop, int numOfPorts);

    void setCpu(const std::string& cpu);
    void setIsALaptop(bool isALaptop);

    std::string getCpu() const;
    bool getIsALaptop() const;
    int getNumOfPorts() const;

    bool connectDevice(PeripheralDevice* device);
    void disconnectDevice(PeripheralDevice* device);
    void printConnected() const;

    operator std::string() const override;
    int getAvailablePorts() const;

    ~Computer();
};