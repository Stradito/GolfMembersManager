#include <iostream>
#include <cstring>
#include "mfrc522.h"
#include "Listener.h"
#include "GolfMembershipManager.h"
#include "MembersEntity.h"

int main(void)
{
    GolfMembershipManager golfMembershipManager;
    golfMembershipManager.run();

    return 0;
}
/*
    while(1)
    {
        listener->checkEvent();
        delay(1000);
        printf("hihi\n");
    }
*/