#pragma once
#include "PeripheralDevice.h"
#include "Computer.h"
#include <string>

class Tablet : public PeripheralDevice, public Computer {
private:
    int screenSize;

public:
    Tablet(int price, const std::string& manufacturer, const std::string& color, const std::string& cpu, int screenSize);

    int getScreenSize() const;
    void setScreenSize(int screenSize);

    // Override the to-string conversion
    operator std::string() const override;

    // Override the connect method
    void connect(Computer& computer) override;

    // Destructor
    ~Tablet();
};