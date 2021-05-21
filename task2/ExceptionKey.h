#pragma once
#include "Exception.h"
class ExceptionKey : protected Exception
{
public:

    ExceptionKey() = delete;

    ExceptionKey (const int &num,const string &error, const string& correction);
    string what () override;
    string fix () override;
    int code () override;

    static bool check_key (const wstring &data,const string str_key);
};