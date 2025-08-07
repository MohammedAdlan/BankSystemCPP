#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"

class clsClientListScreen :protected clsScreen
{
private:
	static void _PirntClientRecordLine(clsBankClient Client)
	{
		cout << setw(8) << left << "" << "| " << left << setw(15) << Client.AccountNumber();
		cout << "| " << left << setw(20) << Client.FullName();
		cout << "| " << left << setw(20) << Client.Email;
		cout << "| " << left << setw(12) << Client.Phone;
		cout << "| " << left << setw(10) << Client.PinCode;
		cout << "| " << left << setw(12) << Client.AccountBalance;
	}
public:

	static void ShowClientsList()
	{
		if (!CheckAccessRights(clsUser::pListClients))
			return; //this will exit the function and it will not execute.

		vector <clsBankClient> vClients = clsBankClient::GetClientsList();
		string Title = "\t\t    Client List Screen";
		string Subtitle = "\t    (" + to_string(vClients.size()) + ") Client(s)";

		DrawScreenHeader(Title, Subtitle);

		cout << setw(8) << left << "" << "\n\t________________________________________________________________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance";
		cout << setw(8) << left << "" << "\n\t________________________________________________________________________________________________\n" << endl;

		if (vClients.size() == 0)
			cout << "\n\t\t\t\t No Clients Available In the system.\n";
		else
		{
			for (clsBankClient& Client : vClients)
			{
				_PirntClientRecordLine(Client);
				cout << endl;
			}
		}

		cout << setw(8) << left << "" << "\n\t________________________________________________________________________________________________\n";
	}
};

