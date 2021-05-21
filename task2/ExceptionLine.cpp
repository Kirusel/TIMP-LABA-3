#include "ExceptionLine.h"

ExceptionLine::ExceptionLine (const int &num,const string &error, const string& correction)
{
    this->num = num;
    this->error = error;
    this->correction=correction;

}
string ExceptionLine::what ()
{
    return "Ошибка: " + error;
}
int ExceptionLine::code ()
{
    return num;
}
string ExceptionLine::fix ()
{
    return correction;
}

bool ExceptionLine::CheckLine ( const string data )
{
    if (data.empty())
        throw ExceptionLine (1, "пустая строка.", "При вводе используйте любые символы.");
    return true;
}