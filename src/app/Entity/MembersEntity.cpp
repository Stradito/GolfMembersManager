#include "MembersEntity.h"
#include <string.h> // == cstring

MembersEntity::MembersEntity()
    : fpDBData(fopen("memberLists.bin", "r+"))
{  
    // fpDBData = fopen("memberLists.bin", "r+");
    loadMembersInfo();
}

MembersEntity::~MembersEntity()
{
}

void MembersEntity::loadMembersInfo()
{
    fpDBData = fopen("memberLists.bin", "r");       // else NULL

    if (fpDBData == NULL) {
        fprintf(stderr, "file open  error!\n");
        return;
    }

    while (fread(&memberInfo, sizeof(MemberInfo), 1, fpDBData))
    {
        vecMembersList.emplace_back(memberInfo);
    }

    fclose(fpDBData);
}

void MembersEntity::addMemberInfo(MemberInfo member)
{
    vecMembersList.emplace_back(member);
}

bool MembersEntity::delMemberInfo(int *cardNum)
{
    std::vector<MemberInfo>::iterator itrMember;
    itrMember = vecMembersList.begin();

    for (itrMember; itrMember != vecMembersList.end(); itrMember++) //같지않으면 계속 반복
    {  
        if(memcmp(itrMember -> cardNum, cardNum, sizeof(itrMember->cardNum))==0)
        {
            vecMembersList.erase(itrMember);
            return true;
        }
    }
    return false;
}

bool MembersEntity::delMemberInfo(std::string name)
{
}

void MembersEntity::printMemberInfo(int index)
{
    if (index > (int)vecMembersList.size()) {
        fprintf(stderr, "out of ranget membercount!\n");
        return;
    }
    printf("%05d %s %s %s %03d-%03d-%03d-%03d-%03d\n",
    vecMembersList[index].id, 
    vecMembersList[index].name, 
    vecMembersList[index].address, 
    vecMembersList[index].phoneNumber,
    vecMembersList[index].cardNum[0],
    vecMembersList[index].cardNum[1],
    vecMembersList[index].cardNum[2],
    vecMembersList[index].cardNum[3],
    vecMembersList[index].cardNum[4]);
}

void MembersEntity::printMemberINfo(int *cardNum)
{
    for (const auto &member : vecMembersList) {
        if (memcmp(member.cardNum, cardNum, sizeof(member.cardNum)) == 0) {
            printMemberInfo(member.id);
            return;
        }
    }
}

void MembersEntity::printMemberInfo(std::string name)
{
    for (const auto &member : vecMembersList) {
        if (strcmp(member.name, name.c_str()) == 0) {
            printMemberInfo(member.id);
            return;
        }
    }
}

bool MembersEntity::findMemberinfo(int *cardNum)
{
    for (const auto &member : vecMembersList) {
        if (memcmp(member.cardNum, cardNum, sizeof(member.cardNum)) == 0) {
            printMemberInfo(member.id);
            return true;
        }
    }
    return false;
}

bool MembersEntity::findMemberinfo(std::string name)
{
    for (const auto &member : vecMembersList) {
        if (strcmp(member.name, name.c_str()) == 0) {
            printMemberInfo(member.id);
            return true;
        }
    }
    return false;
}

void MembersEntity::memortToDB()
{
    fpDBData = fopen("memberLists.bin", "w");       // else NULL
    FILE *fpDBData2 = fopen("memberLists.txt", "w");

    if (fpDBData == NULL) {
        fprintf(stderr, "file open  error!\n");
        return;
    }

    for (const auto &member : vecMembersList) {
        fwrite(&member, sizeof(member), 1, fpDBData);
        fprintf(fpDBData2, "%05d, %s\n", member.id, member.name);
    }
    fclose(fpDBData);
    fclose(fpDBData2);
}