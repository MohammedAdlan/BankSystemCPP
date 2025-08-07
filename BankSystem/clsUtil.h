#pragma once

#include <iostream>
#include "clsDate.h"
using namespace std;

class clsUtil
{
public:
    enum enCharType { SmallLetter = 1, CapitalLetter, Digit, MixChars, SpecialCharacter };

    static void Srand()
    {
        //Seed the random nubmer generate in C++, called only once, and at main function called;
        srand((unsigned)time(NULL));
    }

    static int RandomNumber(int From, int To)
    {
        //to generate a random number
        return (int)rand() % (To - From + 1) + From;
    }

    static char GetRandomCharacter(enCharType CharType)
    {
        //update this method to accept mixchar
        if (CharType == MixChars)
        {
            //capital/small/digits only
            CharType = (enCharType)RandomNumber(1, 3);
        }

        switch (CharType)
        {
        case SmallLetter:
            return char(RandomNumber(97, 122));
        case CapitalLetter:
            return char(RandomNumber(65, 90));
        case SpecialCharacter:
            return char(RandomNumber(33, 47));
        case Digit:
            return char(RandomNumber(48, 57));
        default:
            return char(RandomNumber(65, 90));
        }
    }

    static string GenerateWord(enCharType CharType, short Length)
    {
        string Word = "";

        for (short i = 1; i <= Length; i++)
        {
            Word += GetRandomCharacter(CharType);
        }
        return Word;
    }

    static string GenerateKey(enCharType CharType = CapitalLetter)
    {
        string Key = "";
        Key = GenerateWord(CapitalLetter, 4) + "-";
        Key += GenerateWord(CapitalLetter, 4) + "-";
        Key += GenerateWord(CapitalLetter, 4) + "-";
        Key += GenerateWord(CapitalLetter, 4);
        return Key;
    }

    static void GenerateKeys(short NumberOfKeys, enCharType CharType = CapitalLetter)
    {
        for (int i = 1; i <= NumberOfKeys; i++)
        {
            cout << "Key [" << i << "]: ";
            cout << GenerateKey(CharType) << endl;
        }
    }

    static void FillArrayWithRandomNnumbers(int arr[100], int arrLength, int From, int To)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = RandomNumber(From, To);
    }

    static void FillArrayWithWords(string arr[100], int arrLength, enCharType CharType, short WordLength)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateWord(CharType, WordLength);
    }

    static void FillArrayWithKeys(string arr[100], int arrLength, enCharType CharType)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateKey(CharType);
    }

    static void Swap(int& Num1, int& Num2)
    {
        int Temp = Num1;
        Num1 = Num2;
        Num2 = Temp;
    }

    static void Swap(double& Num1, double& Num2)
    {
        double Temp = Num1;
        Num1 = Num2;
        Num2 = Temp;
    }

    static void Swap(bool& A, bool& B)
    {
        bool Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(char& Letter1, char& Letter2)
    {
        char Temp = Letter1;
        Letter1 = Letter2;
        Letter2 = Temp;
    }

    static void Swap(string& S1, string& S2)
    {
        string Temp = S1;
        S1 = S2;
        S2 = Temp;
    }

    static void Swap(clsDate& Date1, clsDate& Date2)
    {
        clsDate TempDate = Date1;
        Date1 = Date2;
        Date2 = TempDate;
    }

    static void ShuffleArray(int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
    }

    static void ShuffleArray(string arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
    }

    static string Tabs(short NumberOfTabs)
    {
        string t = "";
        for (short i = 0; i < NumberOfTabs; i++)
        {
            t = t + "\t";
            cout << t;
        }
        return t;
    }

    static string NumberToText(int Number)
    {
        if (Number == 0)
        {
            return "";
        }

        if (Number >= 1 && Number <= 19)
        {
            string arr[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
                                 "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
                                 "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
            return arr[Number] + " ";
        }

        if (Number >= 20 && Number <= 99)
        {
            string arr[] = { "","", "Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninty" };
            return arr[Number / 10] + " " + NumberToText(Number % 10);
        }

        if (Number >= 100 && Number <= 199)
        {
            return "One Hundred " + NumberToText(Number % 100);
        }

        if (Number >= 200 && Number <= 999)
        {
            return NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
        }

        if (Number >= 1000 && Number <= 1999)
        {
            return "One Thousand " + NumberToText(Number % 1000);
        }

        if (Number >= 2000 && Number <= 999999)
        {
            return NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
        }

        if (Number >= 1000000 && Number <= 1999999)
        {
            return "One Million " + NumberToText(Number % 1000000);
        }

        if (Number >= 2000000 && Number <= 999999999)
        {
            return NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
        }

        if (Number >= 1000000000 && Number <= 1999999999)
        {
            return "One Billion " + NumberToText(Number % 1000000000);
        }

        if (Number >= 2000000000 && Number <= 999999999999)
        {
            return NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
        }
    }

    static string EncryptText(string EncryptedText, short EncryptionKey = 2)
    {
        for (int i = 0; i < EncryptedText.length(); i++)
        {
            EncryptedText[i] += EncryptionKey;
        }
        return EncryptedText;
    }

    static string DecryptText(string PlainText, short EncryptionKey = 2)
    {

        for (int i = 0; i < PlainText.length(); i++)
        {
            PlainText[i] = char((int)PlainText[i] - EncryptionKey);
        }
        return PlainText;
    }

    static  int ReverseNumber(int Number)
    {

        int Remainder = 0;
        int ReverseNumber = 0;
        while (Number > 0)
        {
            Remainder = Number % 10;
            Number = Number / 10;
            ReverseNumber = ReverseNumber * 10 + Remainder;
        }
        return ReverseNumber;
    }

    static int CountDigitFrequency(int Number, short DigitToCheck)
    {
        int Remainder = 0;
        int FreqCount = 0;
        while (Number > 0)
        {
            Remainder = Number % 10;
            Number = Number / 10;

            if (Remainder == DigitToCheck)
                FreqCount++;
        }
        return FreqCount;
    }

    static int SumOfMatrix(int arr[3][3], short Rows, short Cols)
    {
        short Sum = 0;
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Cols; j++)
            {
                Sum += arr[i][j];
            }
        }
        return Sum;
    }
};

