#include "stdafx.h"
#include "CppPrimerFriend.h"


CppPrimerFriend::CppPrimerFriend()
{
}


CppPrimerFriend::~CppPrimerFriend()
{
}

void CppPrimerFriend::useCppPrimerPrivate(const CppPrimer &insCppPrimer)
{
    // CppPrimerFriend��CppPrimer����Ԫ�࣬���Կ��Է�����private��Ա
    cout << "In CppPrimerFriend, CppPrimer.arithType_bool: " << insCppPrimer.arithType_bool << endl;
}
