#pragma once
#include <string>
using namespace std;
class SubstitutionCipher
{
private:
    int key;

public:
    SubstitutionCipher() = delete;
    SubstitutionCipher(int k);
    wstring Encode(SubstitutionCipher key, wstring& data);
    wstring Decode(SubstitutionCipher key, wstring& data);
};