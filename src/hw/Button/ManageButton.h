#ifndef MANAGEBUTTON_H
#define MANAGEBUTTON_H

#include <string>
#include "Button.h"
#include "DeviceData.h"

class ManageButton : public Button
{
private:
    DeviceData buttonData;

public:
    ManageButton(int pin, std::string name);
    ~ManageButton();
    bool checkButton();
    DeviceData getButtonData();
};

#endif