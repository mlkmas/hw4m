#include "Mouse.h"
#include <iostream>
Mouse::Mouse(int price, const std::string& manufacturer, const std::string& color, bool isWireless, int dpi) :
    PeripheralDevice(price, manufacturer, color, isWireless), dpi(dpi) {}

int Mouse::getDpi() const
{
    return dpi;
}

void Mouse::setDpi(int dpi)
{
    this->dpi = dpi;
}

void Mouse::connect(const Computer& computer)
{
    std::cout << "Connecting a mouse" << std::endl;
    PeripheralDevice::connect(computer);
}

Mouse::operator std::string() const
{
    return PeripheralDevice::operator std::string() + ", Mouse with dpi : " + std::to_string(dpi);
}