#include "Controller.h"

Controller::Controller()
{
    monitor = new Monitor();
    membersManageService = new MembersManageService();
}

Controller::~Controller()
{
}

void Controller::updateEvent(DeviceData data)
{
    if (data.devName == "cardReader") {
        int cardNumber[5];
        for (int i=0; i<5; i++) {
            cardNumber[i] = data.devData[i];
            // std::cout << cardNumber[i] << std::endl;
        }
        // std::cout << cardNumber << std::endl;
        membersManageService->checkCardNumber(cardNumber);
    }

    if (data.devName == "ModeButton") {
        membersManageService->updateStateEvent("ModeButton");
    }

    // std::cout << data.devName << " : ";
    // for (const auto data : data.devData) {
    //     std::cout << std::hex<< data << " ";
    // }
    // std::cout << std::endl;
}