#pragma once
#include <stdexcept>
#include <string>
#include <iostream>
using namespace std;
/// @brief  Класс для обработки ошибок, которые могут возникнуть при взаимодействии с программой
/// @details Класс наследует существующий класс обработки исключений с именем "invalid_argument" из библиотеки "stdexcept".
class MyExceptions : public invalid_argument
{
private:
    int num; ///< атрибут, хранящий код ошибки
    string correction; ///< атрибут, хранящий информацию об исправлении ошибки
public:
    /// @brief  Запрещающий конструктор без параметров
    MyExceptions() = delete;
    /** @brief  Конструктор с параметрами
     * @param num - целочисленное число, хранящее информацию о коде ошибки
     * @param error - строка, хранящая описание ошибки. Данный параметр перегружается конструктором класса "invalid_argument"
     * @param correction - строка, хранящая информацию об исправлении ошибки
     */
    MyExceptions (const string & error, const int &num, const string &fix);
     /// @brief  Предназначен для вывода информации об исправлении ошибки
    void fix ();
    /// @brief  Предназначен для вывода кода ошибки
    void code ();
};