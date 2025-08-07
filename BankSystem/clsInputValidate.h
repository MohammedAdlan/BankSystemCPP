#pragma once
#include <iostream>
#include "clsDate.h"
#include "clsUtil.h"
using namespace std;

class clsInputValidate
{
public:


    static bool IsNumberBetween(short Number, short From, short To)
    {
        return (Number >= From && Number <= To);
    }

    static bool IsNumberBetween(int Number, int From, int To)
    {
        return (Number >= From && Number <= To);
    }

    static bool IsNumberBetween(float Number, float From, float To)
    {
        return (Number >= From && Number <= To);
    }

    static bool IsNumberBetween(double Number, double From, double To)
    {
        return (Number >= From && Number <= To);
    }

    static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
    {
        //Date >= From && Date <= To
        if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
            &&
            (clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)))
            return true;

        //Date <= To && Date >= From
        if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
            &&
            (clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)))
            return true;

        return false;
    }

    static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter Again: ")
    {
        int Number = 0;
        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }
        return Number;
    }

    static int ReadPositiveNumber(string ErrorMessage = "Invalid Number, Enter Again: ")
    {
        int Number = ReadIntNumber();
        while (Number < 0)
        {
            cout << ErrorMessage << endl;
            cin >> Number;
        };

        return Number;
    }

    static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Invalid Number, Enter Again: ")
    {
        short Number = ReadIntNumber();
        while (!IsNumberBetween(Number, From, To))
        {
            cout << ErrorMessage;
            Number = ReadIntNumber();
        };

        return Number;
    }

    static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is Not within range, Enter Again: ")
    {
        int Number = ReadIntNumber();
        while (!IsNumberBetween(Number, From, To))
        {
            cout << ErrorMessage;
            Number = ReadIntNumber();
        };

        return Number;
    }

    static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter Again: ")
    {
        double Number = 0;
        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }
        return Number;
    }

    static float ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter Again: ")
    {
        float Number = 0;
        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }
        return Number;
    }


    static double ReadPositiveDblNumber(string ErrorMessage = "Invalid Number, Enter Again: ")
    {
        double Number = ReadIntNumber();
        while (Number < 0)
        {
            cout << ErrorMessage << endl;
            cin >> Number;
        };

        return Number;
    }

    static int ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is Not within range, Enter Again: ")
    {
        double Number = ReadDblNumber();
        while (!IsNumberBetween(Number, From, To))
        {
            cout << ErrorMessage;
            Number = ReadIntNumber();
        };

        return Number;
    }

    static bool IsValidDate(clsDate Date)
    {
        return clsDate::IsValidDate(Date);
    }

    enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

    static enPrimeNotPrime CheckPrimeNumber(int Number)
    {
        int M = round(Number / 2);
        for (int Counter = 2; Counter <= M; Counter++)
        {
            if (Number % Counter == 0)
                return NotPrime;
        }
        return Prime;
    }

    static bool IsPerfectNumber(int Number)
    {
        int Sum = 0;
        for (int Counter = 1; Counter <= round(Number / 2); Counter++)
        {
            if (Number % Counter == 0)
                Sum += Counter;
        }
        return Sum == Number;
    }

    /* static  int ReverseNumber(int Number)
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
     }*/

    static bool isPalindromeNumber(int Number)
    {
        return Number == clsUtil::ReverseNumber(Number);
    }

    bool AreEqualMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
    {
        return (clsUtil::SumOfMatrix(Matrix1, Rows, Cols) == clsUtil::SumOfMatrix(Matrix2, Rows, Cols));
    }

    static string ReadString()
    {
        string S1 = "";
        //Usage of std::ws will exstract allth whitespace character
        getline(cin >> ws, S1);
        return S1;
    }

};

