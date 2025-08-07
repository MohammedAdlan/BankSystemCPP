#pragma once
#include "clsScreen.h"
#include "clsCurrancy.h"
class clsCurrenciesListScreen : protected clsScreen
{
private:
	static void _PirntCurrencyRecordLine(clsCurrancy Currency)
	{
		cout << setw(8) << left << "" << "| " << left << setw(30) << Currency.Country();
		cout << "| " << left << setw(8) << Currency.CurrencyCode();
		cout << "| " << left << setw(45) << Currency.CurrencyName();
		cout << "| " << left << setw(15) << Currency.Rate();
	}

public:


	static void  ShowUsersList()
	{
		vector <clsCurrancy> vCurrencies = clsCurrancy::GetCurrenciesList();

		string SubTitle = "\t\t[" + to_string(vCurrencies.size()) + "] Currency";
		DrawScreenHeader("\t\t    Currencies List Screen", SubTitle);

		cout << setw(8) << left << "" << "\n\t_________________________________________________________________________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(8) << "Code";
		cout << "| " << left << setw(45) << "Name";
		cout << "| " << left << setw(15) << "Rate/1($)";
		cout << setw(1) << left << "" << "\n\t_________________________________________________________________________________________________________" << endl;

		if (vCurrencies.size() == 0)
			cout << "\n\t\t\t\t\t No Currencies Available In the System!";
		else
			for (clsCurrancy& Currency : vCurrencies)
			{
				cout << endl;
				_PirntCurrencyRecordLine(Currency);
			}

		cout << setw(1) << left << "" << "\n\t_________________________________________________________________________________________________________\n";

	}
};

