#pragma once
#include "clsScreen.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyScreen.h"
#include "clsCurrencyCalculatorScreen.h"
class clsCurrencyExchangeMainScreen : protected clsScreen
{
private:
	enum enCurrenciesMainMenueOptions
	{
		eCurrenciesList = 1, eFindCurrency, eUpdateCurrrencyRate,
		eCurrencyCalculator, eMainMenue
	};

	static short _ReadCurrenciesMainMenueOption()
	{
		cout << setw(37) << left << "" << "   Choose what do you want to do: [1 to 5]: ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter a Numbet Between  [1 to 5]:");
		return Choice;
	}

	static void _GoBackToCurrenciesMenue()
	{
		cout << "\n";
		cout << setw(37) << left << "" << "  Press any press to go back to main menue ...";
		system("pause>0");
		ShowCurrenciesMenue();
	}

	static void _ShowCurrenciesListScreen()
	{
		clsCurrenciesListScreen::ShowUsersList();
	}

	static void _ShowFindCurrencyScreen()
	{
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateCurrencyRateScreen()
	{
		clsUpdateCurrencyScreen::ShowUpdateCurrencyScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _PerformCurrenciesMainMenueOptions(enCurrenciesMainMenueOptions CurrenciesMainMenueOption)
	{
		switch (CurrenciesMainMenueOption)
		{
		case eCurrenciesList:
			system("cls");
			_ShowCurrenciesListScreen();
			_GoBackToCurrenciesMenue();
			break;

		case eFindCurrency:
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrenciesMenue();
			break;

		case eUpdateCurrrencyRate:
			system("cls");
			_ShowUpdateCurrencyRateScreen();
			_GoBackToCurrenciesMenue();
			break;

		case eCurrencyCalculator:
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrenciesMenue();
			break;

		case eMainMenue:
		{
			//break;
		}

		}
	}

public:

	static void ShowCurrenciesMenue()
	{
		system("cls");
		DrawScreenHeader("\t\tCurrency Exchange Main Screen");

		cout << setw(37) << left << "" << "   ------------------------------------------\n";
		cout << setw(37) << left << "" << "\t\t    Currency Exchange Menue \n";
		cout << setw(37) << left << "" << "   ------------------------------------------\n";
		cout << setw(37) << left << "" << "\t  [1] Currencies List\n";
		cout << setw(37) << left << "" << "\t  [2] Find Currency\n";
		cout << setw(37) << left << "" << "\t  [3] Update Currency.\n";
		cout << setw(37) << left << "" << "\t  [4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t  [5] Main Menue.\n";
		cout << setw(37) << left << "" << "   ------------------------------------------\n";
		_PerformCurrenciesMainMenueOptions((enCurrenciesMainMenueOptions)_ReadCurrenciesMainMenueOption());
	}
};

