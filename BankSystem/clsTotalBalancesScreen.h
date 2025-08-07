#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;
class clsTotalBalancesScreen : protected clsScreen
{

private:
	static void PirntClientRecordBalanceLine(clsBankClient Client)
	{
		cout << setw(20) << left << "" << "| " << left << setw(15) << Client.AccountNumber();
		cout << "| " << left << setw(40) << Client.FullName();
		cout << "| " << left << setw(12) << Client.AccountBalance;
	}
public:

	static void ShowTotalBalanceScreen()
	{
		vector <clsBankClient> vClients = clsBankClient::GetClientsList();

		string SubTitle = "\t\t[" + to_string(vClients.size()) + "] Client(s)";
		DrawScreenHeader("\t\t    Total Balance Screen", SubTitle);

		cout << setw(25) << left << "" << "\n\t\t________________________________________________________________________________________________\n" << endl;
		cout << setw(20) << left << "" << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout << setw(25) << left << "" << "\n\t\t________________________________________________________________________________________________" << endl;

		double TotalBalance = clsBankClient::GetTotalBalance();

		if (vClients.size() == 0)
			cout << "\n\t\t\t\t\t No Clients Available In the System!";
		else
			for (clsBankClient& Client : vClients)
			{
				cout << endl;
				PirntClientRecordBalanceLine(Client);
			}

		cout << setw(25) << left << "" << "\n\t\t________________________________________________________________________________________________\n";
		cout << setw(8) << left << "" << "\n\t\t\t\t\t\t Total Balances = " << TotalBalance << endl;
		cout << setw(8) << left << "" << "\t\t\t\t " << clsUtil::NumberToText(TotalBalance) << endl;
	}
};

