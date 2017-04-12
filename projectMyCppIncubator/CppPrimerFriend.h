#pragma once

#include "CppPrimer.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;

class CppPrimerFriend
{
    // ������ĳ�Ա������Ϊ��Ԫ
    friend void CppPrimer::toBeFriendOfCppPrimerFriend(CppPrimerFriend insCppPrimerFriend);

public:
    CppPrimerFriend();
    ~CppPrimerFriend();

    void useCppPrimerPrivate(const CppPrimer &insCppPrimer);

private:
    std::string privateStr{ "Hello, CppPrimerFriend!" };
};

