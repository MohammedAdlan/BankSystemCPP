#pragma once
#include "clsScreen.h"
#include "clsCurrancy.h"
class clsFindCurrencyScreen : protected clsScreen
{
private:

	static void _PrintCurrency(clsCurrancy Currency)
	{
		cout << "\n\n Currency Card:";
		cout << "\n ____________________________\n";
		cout << "\n Coountry  : " << Currency.Country();
		cout << "\n Code      : " << Currency.CurrencyCode();
		cout << "\n Name      : " << Currency.CurrencyName();
		cout << "\n Rate (1$) : " << Currency.Rate();
		cout << "\n ____________________________" << endl;
	}

	static void _ShowResults(clsCurrancy Currency)
	{
		if (!Currency.IsEmpty())
			_PrintCurrency(Currency);
		else
			cout << "\n Curreny was not found!\n";
	}

public:
	static void ShowFindCurrencyScreen()
	{
		DrawScreenHeader("\t\t    Find Currency Screen");

		cout << "   Find By: [1] Code or [2] Country: ";

		short Answer = 1;
		Answer = clsInputValidate::ReadShortNumberBetween(1, 2, "Enter a Numbet Between  [1 to 2]:");

		if (Answer == 1)
		{

			string CurrencyCode = "";
			cout << "\n Please Enter Currency Code: ";
			CurrencyCode = clsInputValidate::ReadString();
			clsCurrancy Currency = clsCurrancy::FindByCode(CurrencyCode);
			_ShowResults(Currency);
		}
		else
		{
			string Country = "";
			cout << "\n Please Enter Country Name: ";
			Country = clsInputValidate::ReadString();
			clsCurrancy Currency = clsCurrancy::FindByCountry(Country);
			_ShowResults(Currency);
		}
	}
};

