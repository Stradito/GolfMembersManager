#ifndef LISTENER_H
#define LISTENER_H

#include "CardReader.h"
#include "Monitor.h"
#include "Controller.h"
#include "ManageButton.h"

class Listener
{
private:
    uint8_t rfidData[16];
    CardReader *rfid;
    ManageButton *modeButton;
    Controller *controller;

public:
    Listener();
    ~Listener();
    void checkEvent();
    bool checkRfid();
};

#endif