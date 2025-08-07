#pragma once

#include <iomanip>
#include <iostream>
#include "clsScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"
#include "clsTotalBalancesScreen.h"

using namespace std;

class clsTransactionsScreen : protected clsScreen
{

private:
	enum enTransactionsMenueOptions
	{
		eDeposit = 1, eWithdraw,
		eShowTotalBalance, eTransfer, eTransferLog, eShowMainMenue
	};

	static short _ReadTransactionsMenueOption()
	{
		cout << setw(37) << left << "" << "   Choose what do you want to do: [1 to 6]: ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6);
		return Choice;
	}

	static void _GoBackToTransactionsMenue()
	{
		cout << setw(37) << left << "" << "\n  Press any press to go back to main menue ...";
		system("pause>0");
		ShowTransactionsMenue();
	}

	static void _ShowDepositScreen()
	{
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWitdrawScreen()
	{
		clsWithdrawScreen::ShowWitdrawScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		clsTotalBalancesScreen::ShowTotalBalanceScreen();
	}

	static void _ShowTransferScreen()
	{
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransfersLogScreen()
	{
		clsTransferLogScreen::ShowTransferLogScreen();
	}

	static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactioinsMenueOption)
	{
		switch (TransactioinsMenueOption)
		{
		case eDeposit:
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenue();
			break;

		case eWithdraw:
			system("cls");
			_ShowWitdrawScreen();
			_GoBackToTransactionsMenue();
			break;

		case eShowTotalBalance:
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionsMenue();
			break;

		case eTransfer:
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionsMenue();
			break;
		case eTransferLog:
			system("cls");
			_ShowTransfersLogScreen();
			_GoBackToTransactionsMenue();
			break;
		case eShowMainMenue:
		{

		}
		}
	}

public:

	static void ShowTransactionsMenue()
	{
		if (!CheckAccessRights(clsUser::pTransactions))
			return; //this will exit the function and it will not execute.

		system("cls");
		DrawScreenHeader("\t\t    Transactions Screen");

		cout << setw(37) << left << "" << "   ------------------------------------------\n";
		cout << setw(37) << left << "" << "\t\t     Transactions Menue\n";
		cout << setw(37) << left << "" << "   ------------------------------------------\n";
		cout << setw(37) << left << "" << "\t  [1] Deposit.\n";
		cout << setw(37) << left << "" << "\t  [2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t  [3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t  [4] Transfer.\n";
		cout << setw(37) << left << "" << "\t  [5] Transfer Log.\n";
		cout << setw(37) << left << "" << "\t  [6] Main Menue.\n";
		cout << setw(37) << left << "" << "   ------------------------------------------\n";
		_PerformTransactionsMenueOption((enTransactionsMenueOptions)_ReadTransactionsMenueOption());
	}

};

