#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "clsString.h"
using namespace std;

class clsCurrancy
{
private:
    enum  enMode { EmptyMode = 0, UpdateMode };

    enMode _Mode = UpdateMode;
    string _Country = "";
    string _CurrencyCode = "";
    string _CurrencyName = "";
    float _Rate = 0;

    static clsCurrancy _ConvertLineToCurrencyObject(string Line, string Separator = "#//#")
    {
        vector <string> vUserData;
        vUserData = clsString::Split(Line, Separator);

        return clsCurrancy(UpdateMode, vUserData[0], vUserData[1], vUserData[2], stod(vUserData[3]));
    }

    static string _ConvertCurrencyObjectToLine(clsCurrancy Currency, string Separator = "#//#")
    {
        string stCurrencyRecord = "";
        stCurrencyRecord += Currency.Country() + Separator;
        stCurrencyRecord += Currency.CurrencyCode() + Separator;
        stCurrencyRecord += Currency.CurrencyName() + Separator;
        stCurrencyRecord += to_string(Currency.Rate());

        return stCurrencyRecord;
    }

    static vector <clsCurrancy> _LoadCurrenciesDataFromFile()
    {
        vector <clsCurrancy> vCurrencies;

        fstream MyFile;
        MyFile.open("Currencies.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line = "";

            while (getline(MyFile, Line))
            {
                vCurrencies.push_back(_ConvertLineToCurrencyObject(Line));
            }
            MyFile.close();
        }
        return vCurrencies;
    }

    static void _SaveCurrencyDataToFile(vector <clsCurrancy> vCurrencies)
    {
        fstream MyFile;
        MyFile.open("Currencies.txt", ios::out); //overwrite

        if (MyFile.is_open())
        {
            for (clsCurrancy Currency : vCurrencies)
            {
                MyFile << _ConvertCurrencyObjectToLine(Currency) << "\n";
            }
            MyFile.close();
        }

    }

    void _Update()
    {
        vector <clsCurrancy> _vCurrencies;
        _vCurrencies = _LoadCurrenciesDataFromFile();

        for (clsCurrancy& crn : _vCurrencies)
        {
            if (crn.CurrencyCode() == CurrencyCode())
            {
                crn = *this;
                break;
            }
        }
        _SaveCurrencyDataToFile(_vCurrencies);
    }

    static clsCurrancy _GetEmptyCurrencyObject()
    {
        return clsCurrancy(enMode::EmptyMode, "", "", "", 0);
    }


public:
    clsCurrancy(enMode Mode, string Country, string Code, string Name, float Rate = 0)
    {
        _Mode = Mode;
        _Country = Country;
        _CurrencyCode = Code;
        _CurrencyName = Name;
        _Rate = Rate;
    }

    static vector <clsCurrancy> GetAllUSDRate()
    {
        return _LoadCurrenciesDataFromFile();
    }

    bool IsEmpty()
    {
        return (_Mode == EmptyMode);
    }

    string Country()
    {
        return _Country;
    }

    string CurrencyCode()
    {
        return _CurrencyCode;
    }

    string CurrencyName()
    {
        return _CurrencyName;
    }

    void UpdateRate(float Rate)
    {
        _Rate = Rate;
        _Update();
    }

    float Rate()
    {
        return _Rate;
    }

    static clsCurrancy FindByCode(string CurrencyCode)
    {
        CurrencyCode = clsString::UpperAllString(CurrencyCode);

        fstream MyFile;
        MyFile.open("Currencies.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line = "";
            while (getline(MyFile, Line))
            {
                clsCurrancy Currency = _ConvertLineToCurrencyObject(Line);

                if (Currency.CurrencyCode() == CurrencyCode)
                {
                    MyFile.close();
                    return Currency;
                }
            }
            MyFile.close();
        }
        return _GetEmptyCurrencyObject();
    }

    static clsCurrancy FindByCountry(string Country)
    {
        fstream MyFile;
        MyFile.open("Currencies.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line = "";
            while (getline(MyFile, Line))
            {
                clsCurrancy Currency = _ConvertLineToCurrencyObject(Line);

                if (clsString::UpperAllString(Currency.Country()) == clsString::UpperAllString(Country))
                {
                    MyFile.close();
                    return Currency;
                }
            }
            MyFile.close();
        }
        return _GetEmptyCurrencyObject();
    }


    static bool IsCurrencyExist(string CurrencyCode)
    {
        clsCurrancy User = clsCurrancy::FindByCode(CurrencyCode);
        return (!User.IsEmpty());
    }

    static vector <clsCurrancy> GetCurrenciesList()
    {
        return _LoadCurrenciesDataFromFile();
    }

    float ConvertToUSD(float Amount)
    {
        return (float)(Amount / Rate());
    }

    float ConvertToOtherCurrency(float Amount, clsCurrancy Currency)
    {
        float AmountInUSD = ConvertToUSD(Amount);

        if (Currency.CurrencyCode() == "USD")
            return AmountInUSD;

        return (float)(AmountInUSD * Currency.Rate());
    }
};

