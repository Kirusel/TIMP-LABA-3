#include "Exceptions.h"

MyExceptions::MyExceptions(const string & error, const int &num, const string &fix) : invalid_argument(error)
{
    this->num = num;
    this->correction = fix;
}
void  MyExceptions::code()
{
    cout<< "Код ошибки: " << num << endl;
}
void MyExceptions::fix() {
    cout<< correction << endl;
    }