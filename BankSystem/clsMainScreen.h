#pragma once
#include <iostream>
#include <iomanip>
#include "Global.h"
#include "clsScreen.h"
#include "clsLoginScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsFindClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyExchangeMainScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"

using namespace std;

class clsMainScreen : protected clsScreen
{
private:
	enum enMainMenueOptions
	{
		eClientLists = 1, eAddNewClient,
		eDeleteClient, eUpdateClient,
		eFindClient, eShowTransactionsMenue,
		eManageUsers, eLoginRegister, eCurrencyExchange, eExit
	};

	static short _ReadMainMenueOption()
	{
		cout << setw(37) << left << "" << "   Choose what do you want to do: [1 to 10]: ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 10, "Enter a Number Between: [1 to 10]:");
		return Choice;
	}

	static void _GoBackToMainMenue()
	{
		cout << "\n";
		cout << setw(37) << left << "" << "  Press any press to go back to main menue ...";
		system("pause>0");
		ShowMainMenue();
	}

	static void _ShowAllClientsScreen()
	{
		clsClientListScreen::ShowClientsList();
	}

	static void _ShowAddNewClientsScreen()
	{
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}

	static void _ShowDeleteClientScreen()
	{
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientScreen()
	{
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientScreen()
	{
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionsMenue()
	{
		clsTransactionsScreen::ShowTransactionsMenue();
	}

	static void _ShowManageUsersMenue()
	{
		clsManageUsersScreen::ShowManageUsersMenue();
	}

	static void _ShowLoginRegisterScreen()
	{
		clsLoginRegisterScreen::ShowLoginRegisterScreen();
	}

	static void _ShowCurrencyExchangeMainMenue()
	{
		clsCurrencyExchangeMainScreen::ShowCurrenciesMenue();
	}

	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");

	}

	static void _PerformMainMenueOptions(enMainMenueOptions MainMenueOption)
	{
		switch (MainMenueOption)
		{
		case eClientLists:
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenue();
			break;

		case eAddNewClient:
			system("cls");
			_ShowAddNewClientsScreen();
			_GoBackToMainMenue();
			break;

		case eDeleteClient:
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenue();
			break;

		case eUpdateClient:
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenue();
			break;

		case eFindClient:
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenue();
			break;

		case eShowTransactionsMenue:
			system("cls");
			_ShowTransactionsMenue();
			_GoBackToMainMenue();
			break;

		case eManageUsers:
			system("cls");
			_ShowManageUsersMenue();
			_GoBackToMainMenue();
			break;

		case eLoginRegister:
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenue();
			break;

		case eCurrencyExchange:
			system("cls");
			_ShowCurrencyExchangeMainMenue();
			_GoBackToMainMenue();
			break;

		case eExit:
			system("cls");
			_Logout();
			break;
		}
	}

public:
	static void ShowMainMenue()
	{
		system("cls");
		DrawScreenHeader("\t\t\tMain Screen");

		cout << setw(37) << left << "" << "   ------------------------------------------\n";
		cout << setw(37) << left << "" << "\t\t    Main Menue Screen\n";
		cout << setw(37) << left << "" << "   ------------------------------------------\n";
		cout << setw(37) << left << "" << "\t  [1]  Show Client List\n";
		cout << setw(37) << left << "" << "\t  [2]  Add New Client\n";
		cout << setw(37) << left << "" << "\t  [3]  Delete Client.\n";
		cout << setw(37) << left << "" << "\t  [4]  Update Client.\n";
		cout << setw(37) << left << "" << "\t  [5]  Find Client.\n";
		cout << setw(37) << left << "" << "\t  [6]  Transactions.\n";
		cout << setw(37) << left << "" << "\t  [7]  Manage users.\n";
		cout << setw(37) << left << "" << "\t  [8]  Login Register.\n";
		cout << setw(37) << left << "" << "\t  [9]  Currency Exchange.\n";
		cout << setw(37) << left << "" << "\t  [10] Logout.\n";
		cout << setw(37) << left << "" << "   ------------------------------------------\n";
		_PerformMainMenueOptions((enMainMenueOptions)_ReadMainMenueOption());
	}

};

