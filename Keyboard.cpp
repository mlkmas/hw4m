#include "Keyboard.h"
#include <iostream>

Keyboard::Keyboard(int price, const std::string& manufacturer, const std::string& color, bool isWireless, int numOfKeys) :
    PeripheralDevice(price, manufacturer, color, isWireless), numOfKeys(numOfKeys) {}

int Keyboard::getNumberOfKeys() const
{
    return numOfKeys;
}

void Keyboard::setNumberOfKeys(int nok)
{
    numOfKeys = nok;
}

void Keyboard::connect(const Computer& computer)
{
    std::cout << "Connecting a keyboard" << std::endl;
    PeripheralDevice::connect(computer);
}

Keyboard::operator std::string() const
{
    return PeripheralDevice::operator std::string() + " Keyboard with " + std::to_string(numOfKeys) + " keys";
}