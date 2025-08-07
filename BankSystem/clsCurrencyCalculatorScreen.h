#pragma once
#include "clsScreen.h"
#include "clsCurrancy.h"
#include "clsInputValidate.h"
class clsCurrencyCalculatorScreen : protected clsScreen
{
private:
	static float _ReadAmount()
	{
		cout << "\n Please Enter Amount To Exchange: ";
		float Amount = 0;

		Amount = clsInputValidate::ReadPositiveDblNumber();
		return Amount;

	}

	static clsCurrancy _GetCurrency(string Message)
	{
		cout << "\n " << Message;
		string CurrencyCode = "";

		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrancy::IsCurrencyExist(CurrencyCode))
		{
			cout << "\n Curreny is Not found, Choose another One: ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrancy Currency = clsCurrancy::FindByCode(CurrencyCode);
		return Currency;
	}

	static void _PrintCurrency(clsCurrancy Currency, string Title)
	{
		cout << "\n\n " << Title;
		cout << "\n ____________________________\n";
		cout << "\n Coountry  : " << Currency.Country();
		cout << "\n Code      : " << Currency.CurrencyCode();
		cout << "\n Name      : " << Currency.CurrencyName();
		cout << "\n Rate (1$) : " << Currency.Rate();
		cout << "\n ____________________________" << endl;
	}

	static void _PrintCalculationsResults(float Amount, clsCurrancy Currency1, clsCurrancy Currency2)
	{
		_PrintCurrency(Currency1, "Convert From:");
		float AmountInUSD = Currency1.ConvertToUSD(Amount);

		cout << "\n " << Amount << " " << Currency1.CurrencyCode() << " = " << AmountInUSD << "USD" << endl;

		if (Currency2.CurrencyCode() == "USD")
		{
			return;
		}

		cout << "\n Converting from USD to: \n ";
		_PrintCurrency(Currency2, "To:");

		float AmountInCurrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);
		cout << "\n " << Amount << " " << Currency1.CurrencyCode() << " = " << AmountInCurrency2 << " " << Currency2.CurrencyCode() << endl;

	}

public:
	static void ShowCurrencyCalculatorScreen()
	{

		char Continue = 'y';

		while (toupper(Continue) == 'Y')
		{
			system("cls");
			DrawScreenHeader("\t\t    Exchange Currency Screen");

			clsCurrancy CurrencyFrom = _GetCurrency("Please Enter Currency1 Code: ");
			clsCurrancy CurrencyTo = _GetCurrency("Please Enter Currency2 Code: ");
			float Amount = _ReadAmount();

			_PrintCalculationsResults(Amount, CurrencyFrom, CurrencyTo);

			cout << "\n\n Do you want to perform another calculation [Y/N]: ";
			cin >> Continue;

		};

	}
};

