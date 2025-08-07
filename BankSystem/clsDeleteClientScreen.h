#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsDeleteClientScreen : protected clsScreen
{
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\n\n Client Card:";
		cout << "\n ---------------------------------";
		cout << "\n Acc NO    : " << Client.AccountNumber();
		cout << "\n First Name: " << Client.FirstName;
		cout << "\n Last Name : " << Client.LastName;
		cout << "\n Full Name : " << Client.FullName();
		cout << "\n Email     : " << Client.Email;
		cout << "\n Phone     : " << Client.Phone;
		cout << "\n Password  : " << Client.PinCode;
		cout << "\n Balance   : " << Client.AccountBalance;
		cout << "\n ---------------------------------" << endl;
	}

public:

	static void ShowDeleteClientScreen()
	{
		if (!CheckAccessRights(clsUser::pDeleteClient))
			return; //this will exit the function and it will not execute.

		DrawScreenHeader("\t\t    Delete Client Screen");

		string AccountNumber = "";

		cout << "\n Please Enter AccountNumber: ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\n AccountNumber is Not found, Choose another One: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		char Answer = 'n';
		cout << "\n\n Are you  sure you want to delete this client? [Y/N]: ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (Client1.Delete())
			{
				cout << "\n Account Deleted Successfully.\n";
				_PrintClient(Client1);
			}
			else
			{
				cout << "\n Error Account was not Deleted.\n";
			}
		}

	}
};

