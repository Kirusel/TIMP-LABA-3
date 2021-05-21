#pragma once
#include <string>
#include <iostream>
using namespace std;
class Exception
{
protected:
    string error; 
    int num;    
    string correction;  
public:
    virtual string what () = 0;
    virtual int code () = 0;
    virtual string fix () = 0;
};
