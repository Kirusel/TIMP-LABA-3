#include "ExceptionKey.h"

ExceptionKey::ExceptionKey (const int &num,const string &error, const string& correction)
{
    this->num = num;
    this->error = error;
    this->correction=correction;

}
string ExceptionKey::what ()
{
    return "Ошибка: " + error;
}
int ExceptionKey::code ()
{
    return num;
}
string ExceptionKey::fix ()
{
    return correction;
}

bool ExceptionKey::check_key ( const wstring &data,const string str_key )
{
    int key_Res;
    if (str_key.empty())
        throw ExceptionKey(2,"пустой ключ.","Ключ должен быть натуральным числом и не превашать размера строки.");
    if (str_key.find_first_not_of("-0123456789",0)!=string::npos) {
        throw ExceptionKey(3,"некорректный ключ.","Ключ должен быть натуральным числом и не превашать размера строки.");
    }
    key_Res = stoi(str_key);
    const int dlinastroki = data.size();
    if (key_Res > dlinastroki || key_Res <= 0) {
        throw ExceptionKey(4,"некорректный ключ.","Ключ должен быть натуральным числом и не превашать размера строки.");
    }
    return true;
}