#pragma once
#include "clsScreen.h"
#include "clsCurrancy.h"
#include "clsInputValidate.h"

class clsUpdateCurrencyScreen : protected clsScreen
{
private:
	static float _ReadRate()
	{
		float NewRate = 0;
		cout << "\n Enter New Rate: ";
		NewRate = clsInputValidate::ReadFloatNumber();
		return NewRate;
	}

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

public:
	static void ShowUpdateCurrencyScreen()
	{
		DrawScreenHeader("\t\t    Update Currency Screen");
		string CurrencyCode = "";

		cout << "\n Please Enter Currency Code: ";
		CurrencyCode = clsInputValidate::ReadString();


		while (!clsCurrancy::IsCurrencyExist(CurrencyCode))
		{
			cout << "\n Curreny is Not found, Choose another One: ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrancy Currency = clsCurrancy::FindByCode(CurrencyCode);
		_PrintCurrency(Currency);

		char Answer = 'n';

		cout << " Are you sure you want to update the rate of this Currency [Y/N]: ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			cout << "\n Update Currency Rate: ";
			cout << "\n__________________________\n";
			Currency.UpdateRate(_ReadRate());
			cout << "\n Currency Rate Updated Successfully.";
			_PrintCurrency(Currency);
		}
	}
};

