#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include "Monitor.h"
#include "DeviceData.h"

class Controller
{
private:
    Monitor *monitor;

public:
    Controller();
    ~Controller();
    void updateEvent(DeviceData data);
};

#endif