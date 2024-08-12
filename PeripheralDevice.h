#pragma once
#include "Item.h"  // Include Item.h since PeripheralDevice inherits from Item

// Forward declaration of the Computer class
class Computer;

class PeripheralDevice : public virtual Item {
private:
    std::string color;
    bool isWireless;
    Computer* connectedComputer;  // Pointer to a Computer object

public:
    PeripheralDevice(int price, const std::string& manufacturer, const std::string& color, bool isWireless);

    std::string getColor() const;
    bool getIsWireless() const;
    void setColor(const std::string& color);
    void setIsWireless(bool isWireless);

    virtual void connect(Computer& computer);
    virtual void connect(const Computer& computer);
    bool connectToDevice(Computer& computer);
    void disconnect();

    operator std::string() const override;
    
    virtual ~PeripheralDevice();
};