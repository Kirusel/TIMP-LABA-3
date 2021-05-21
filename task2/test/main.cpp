#include <UnitTest++/UnitTest++.h>
#include "/home/kirussell/labworks/lab3_11/ExceptionLine.h"
#include "/home/kirussell/labworks/lab3_11/ExceptionLine.cpp"
#include "/home/kirussell/labworks/lab3_11/ExceptionKey.cpp"
#include "/home/kirussell/labworks/lab3_11/ExceptionKey.h"
#include "/home/kirussell/labworks/lab3_11/SubstitutionCipher.h"
#include "/home/kirussell/labworks/lab3_11/SubstitutionCipher.cpp"

SUITE(ExceptionStrokaTest)
{
    TEST(StringOfRussianLetters) {
        CHECK_EQUAL(true, ExceptionLine::CheckLine("проверкарусскойстроки"));
    }
    TEST(StringOfEnglishLetters) {
        CHECK_EQUAL(true, ExceptionLine::CheckLine("test"));
    }
    TEST(mixt_of_English_and_Russian_letters_andSpace) {
        CHECK_EQUAL(true, ExceptionLine::CheckLine("русская строка и test"));
    }
    TEST(All_characters) {
        CHECK_EQUAL(true, ExceptionLine::CheckLine("русская строка test 123 !"));
    }
    TEST(Empty_Stroka) {
        CHECK_THROW(ExceptionLine::CheckLine(""),ExceptionLine);
    }
}

SUITE(ExceptionStrokaKeyTest)
{
    wstring test = L"hello world";
    TEST(Correct_key) {
        CHECK_EQUAL(true, ExceptionKey::check_key(test,"3"));
    }
    TEST(The_key_is_an_unnatural_number) {
        CHECK_THROW(ExceptionKey::check_key(test,"-8"),ExceptionKey);
    }
    TEST(A_key_that_is_greater_than_or_equal_to_the_size_of_the_string) {
        CHECK_THROW(ExceptionKey::check_key(test,"12"),ExceptionKey);
    }
    TEST(A_characters_in_the_key_instead_of_numbers) {
        CHECK_THROW(ExceptionKey::check_key(test,"test()рус"),ExceptionKey);
    }
    TEST(The_key_contains_symbols_and_numbers) {
        CHECK_THROW(ExceptionKey::check_key(test,"3test"),ExceptionKey);
    }
    TEST(Empty_key) {
        CHECK_THROW(ExceptionKey::check_key(test,""),ExceptionKey);
    }
}

SUITE(EncodeTest)
{
    const int key = 3;
    SubstitutionCipher test(key);
    TEST(Uppercase_Russian_letters) {
        wstring open_text = L"ПРОВЕРКАРАБОТЫ";
        wstring result_correct = L"ПВКАТРЕАБЫОРРО";
        CHECK_EQUAL(true, result_correct == test.Encode(test,open_text));
    }
     TEST(Lowercase_Russian_letters) {
        wstring open_text = L"проверкаработы";
        wstring result_correct = L"пвкатреабыорро";
        CHECK_EQUAL(true, result_correct == test.Encode(test,open_text));
    }
    TEST(Uppercase_English_letters) {
        wstring open_text = L"HELLOWORLD";
        wstring result_correct = L"HLODEOR LWL";
        CHECK_EQUAL(true, result_correct == test.Encode(test,open_text));
    }
    TEST(Lowercase_English_letters) {
        wstring open_text = L"helloworld";
        wstring result_correct = L"hlodeor lwl";
        CHECK_EQUAL(true, result_correct == test.Encode(test,open_text));
    }
    TEST(mixt_of_English_and_Russian_letters_and_Space) {
        wstring open_text = L"hello мир world привет";
        wstring result_correct = L"hlм r итeoиwlпв l рodре";
        CHECK_EQUAL(true, result_correct == test.Encode(test,open_text));
    }
    TEST(Special_Characters) {
        wstring open_text = L"!234%^&*()";
        wstring result_correct = L"!$&)@%* #^(";
        CHECK_EQUAL(true, result_correct == test.Encode(test,open_text));
    }
    TEST(Numbers_Characters) {
        wstring open_text = L"0123456789";
        wstring result_correct = L"0369147 258";
        CHECK_EQUAL(true, result_correct == test.Encode(test,open_text));
    }
    TEST(All_characters) {
        wstring open_text = L"Проверка Работы 123 !";
        wstring result_correct = L"ПвкРо 3реаат1 ор бы2!";
        CHECK_EQUAL(true, result_correct == test.Encode(test,open_text));
    }
}

SUITE(DecodeTest)
{
    const int key = 3;
    SubstitutionCipher test(key);
    TEST(Uppercase_Russian_letters) {
        wstring cipher_text = L"ПВКАТРЕАБЫОРРО";
        wstring result_correct = L"ПРОВЕРКАРАБОТЫ";
        CHECK_EQUAL(true, result_correct == test.Decode(test,cipher_text));
    }
     TEST(Lowercase_Russian_letters) {
        wstring cipher_text = L"пвкатреабыорро";
        wstring result_correct = L"проверкаработы";
        CHECK_EQUAL(true, result_correct == test.Decode(test,cipher_text));
    }
    TEST(Uppercase_English_letters) {
        wstring cipher_text = L"HLODEOR LWL";
        wstring result_correct = L"HELLOWORLD ";
        CHECK_EQUAL(true, result_correct == test.Decode(test,cipher_text));
    }
    TEST(Lowercase_English_letters) {
        wstring cipher_text = L"hlodeor lwl";
        wstring result_correct = L"helloworld ";
        CHECK_EQUAL(true, result_correct == test.Decode(test,cipher_text));
    }
    TEST(mixt_of_English_and_Russian_letters_and_Space) {
        wstring cipher_text = L"hlм итeoипв l рре";
        wstring result_correct = L"hello мир привет ";
        CHECK_EQUAL(true, result_correct == test.Decode(test,cipher_text));
    }
    TEST(Special_Characters) {
        wstring cipher_text = L"!$&)@%* #^(";
        wstring result_correct = L"!"№;%:?*()";
        CHECK_EQUAL(true, result_correct == test.Decode(test,cipher_text));
    }
    TEST(Numbers_Characters) {
        wstring cipher_text = L"0369147 258";
        wstring result_correct = L"0123456789 ";
        CHECK_EQUAL(true, result_correct == test.Decode(test,cipher_text));
    }
    TEST(All_characters) {
        wstring cipher_text = L"ПвкРо 3реаат1 ор бы2!";
      wstring result_correct = L"Проверка Работы 123 !";
        CHECK_EQUAL(true, result_correct == test.Decode(test,cipher_text));
    }
}

int main(int argc, char **argv)
{
	return UnitTest::RunAllTests();
}
