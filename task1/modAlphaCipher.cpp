#include "modAlphaCipher.h"

modAlphaCipher::modAlphaCipher(wstring skey)
{
    for (unsigned i=0; i<numAlpha.size(); i++) {
        alphaNum[numAlpha[i]]=i;
    }
    key = convert(getValidKey(skey));
}
wstring modAlphaCipher::encrypt(const wstring& open_text)
{
    vector<int> work = convert(getValidAlphabetText(open_text));
    for(unsigned i=0; i < work.size(); i++) {
        work[i] = (work[i] + key[i % key.size()]) % alphaNum.size();
    }
    return convert(work);
}
wstring modAlphaCipher::decrypt(const wstring& cipher_text)
{
    vector<int> work = convert(getValidAlphabetText(cipher_text));
    for(unsigned i=0; i < work.size(); i++) {
        work[i] = (work[i] + alphaNum.size() - key[i % key.size()]) % alphaNum.size();
    }
    return convert(work);
}
inline vector<int> modAlphaCipher::convert(const wstring& s)
{
    vector<int> result;
    for(auto c:s) {
        result.push_back(alphaNum[c]);
    }
    return result;
}
inline wstring modAlphaCipher::convert(const vector<int>& v)
{
    wstring result;
    for(auto i:v) {
        result.push_back(numAlpha[i]);
    }
    return result;
}
inline wstring modAlphaCipher::getValidKey(const wstring & s)
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    if (s.size()==0)
        throw MyExceptions(string("вы ввели пустой ключ."), 1, "Ключ должен состоять только из строки русских букв.");
    wstring wst = s;
    for (size_t i = 0; i < wst.size(); i++) {
        if (iswalpha(wst[i])==0) {
            throw MyExceptions(string("в вашем ключе присутствуют недопустимые символы."), 2, "Ключ должен состоять только из строки русских букв.");
            break;
        }
        if (iswlower(wst[i]))
            wst[i] = towupper(wst[i]);
    }
    return wst;
}

inline wstring modAlphaCipher::getValidAlphabetText(const wstring & s)
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    if (s.size()==0)
        throw MyExceptions(string("вы ввели пустой текст."), 3, "Текст должен состоять только из строки русских букв.");
    wstring wst = s;
    for (size_t i = 0; i < wst.size(); i++) {
        if (iswalpha(wst[i])==0) {
            throw MyExceptions(string("в вашем тексте присутствуют недопустимые символы."), 4, "Текст должен состоять только из строки русских букв.");
            break;
        }
        if (iswlower(wst[i]))
            wst[i] = towupper(wst[i]);
    }
    return wst;
}