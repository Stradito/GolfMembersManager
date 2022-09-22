#include "MembersManageService.h"

MembersManageService::MembersManageService()
{
    membersEntity = new MembersEntity();
    membersManagerState = CARD_READER;
}

MembersManageService::~MembersManageService()
{
}

void MembersManageService::updateStateEvent(std::string devName)
{
    switch (membersManagerState)
    {
    case CARD_READER :
        if(devName == "ModeButton") {
            membersManagerState = CARD_REGISTER;
            printf("changed to CARD_REGISTER State\n");
        }
        break;

    case CARD_REGISTER :
        if(devName == "ModeButton") {
            membersManagerState = CARD_READER;
            printf("changed to CARD_READER State\n");
        }
        break;
    }
}

void MembersManageService::checkCardNumber(int *cardNum)
{
    static int id = 100000;
    char name[20];
    char address[40];
    char phoneNumber[15];
        
    switch (membersManagerState)
    {
    case CARD_READER:
        if (membersEntity->findMemberinfo(cardNum))
        {
            printf("Registerd Member!\n");
        }
        else
        {
            printf("Not Registerd Member!\n");
        }
        break;

    case CARD_REGISTER:
        std::cout << "Name : ";
        std::cin >> name;
        std::cout << "address : ";
        std::cin >> address;
        std::cout << "phoneNumber : ";
        std::cin >> phoneNumber;
        MemberInfo tempMember;
        tempMember.id = id;
        id++;
        strcpy(tempMember.name, name);
        strcpy(tempMember.address, address);
        strcpy(tempMember.phoneNumber, phoneNumber);
        memcpy(tempMember.cardNum, cardNum, sizeof(tempMember.cardNum));
        membersEntity->addMemberInfo(tempMember);
        
        // MemberInfo tempMember;
        // tempMember.id = 100000;
        // strcpy(tempMember.name, "LeeSoonShin");
        // strcpy(tempMember.address, "LotteTower 101dong-123ho");
        // strcpy(tempMember.phoneNumber, "010-1234-5678");
        // memcpy(tempMember.cardNum, cardNum, sizeof(tempMember.cardNum));
        // membersEntity->addMemberInfo(tempMember);

        printf("Member Registered!\n");
        break;
    }
}