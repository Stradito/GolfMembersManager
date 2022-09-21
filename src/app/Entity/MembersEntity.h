#ifndef MEMBERSENTITY_H
#define MEMBERSENTITY_H

#include <vector>
#include <iostream>
#include <string>
#include "MemberInfo.h"

class MembersEntity
{
private:
    std::vector<MemberInfo> vecMembersList;
    MemberInfo memberInfo;
    FILE *fpDBData;

public:
    MembersEntity();
    ~MembersEntity();
    void loadMembersInfo();
    void addMemberInfo(MemberInfo member);
    bool delMemberInfo(int *cardNum);
    bool delMemberInfo(std::string name);
    void printMemberInfo(int index);
    void printMemberINfo(int *cardNum);
    void printMemberInfo(std::string name);
    // bool findMemberinfo(int id);
    bool findMemberinfo(int *cardNum);
    bool findMemberinfo(std::string name);
    void memortToDB();
};

#endif