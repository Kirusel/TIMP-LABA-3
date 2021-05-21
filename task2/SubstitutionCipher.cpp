#include "SubstitutionCipher.h"

SubstitutionCipher::SubstitutionCipher(int k)
{
    this->key=k;
}

wstring SubstitutionCipher::Encode(SubstitutionCipher key, wstring& data)
{
    wstring Result;
    const int stroki = ((data.size()-1)/key.key)+1; // количество строк по формуле
    int index = 0; // для строки
    wchar_t matr[stroki][key.key];
    for (auto i = 0; i <stroki; i++) {
        for (auto j = 0; j < key.key; j++ ) {
            if (index < data.size()) {
                matr[i][j] = data[index]; // записываем символы строки в таблицу (слева-направо)
                index++;
            } else {
                matr[i][j] =' ';
            }
        }
    }
    
    index=0;
    for (auto i = 0; i < key.key; i++) {
        for (auto j = 0; j < stroki; j++ ) {
            if (index <= data.size())
                Result.push_back(matr[j][i]);
                index++;
        }
    }
    Result[index] = '\0';
    return Result;
}

wstring SubstitutionCipher::Decode(SubstitutionCipher key, wstring &data)
{
    wstring Result;
    int index = 0; // для строки
    const int stroki = ((data.size()-1)/key.key)+1; // количество строк по формуле
    wchar_t matr[stroki][key.key];

    for (auto i = 0; i < key.key; i++) {
        for (auto j = 0; j < stroki; j++ ) {
            if (index < data.size()) {
                matr[j][i] = data[index];
                index++;
            } else {
                matr[j][i] = ' ';
                index++;
            }
        }
    }
    index = 0;
    for(auto i = 0; i < stroki; i++) {
        for (auto j = 0; j< key.key; j++) {
            if (index<data.size())
                Result.push_back(matr[i][j]);
                index++;
        }
    }
    Result[index] = '\0';
    return Result;
}