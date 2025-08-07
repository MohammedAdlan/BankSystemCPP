#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsWithdrawScreen : protected clsScreen
{
private:

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
	static void ShowWitdrawScreen()
	{
		DrawScreenHeader("\t\t\tWithdraw Screen");

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

		cout << "\n\n Please Enter wittdraw Amount: ";
		float Amount = clsInputValidate::ReadPositiveDblNumber();

		char Answer = 'n';
		cout << "\n\n Are you  sure you want to perform this transaction? [Y/N]: ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (Client1.Withdraw(Amount))
			{
				cout << "\n Successfully.";
				cout << "\n\n ------------------------- \n\n";
				cout << " New Balance:   " << Client1.AccountBalance;
				cout << "\n\n ------------------------- \n";

			}
			else
			{
				cout << "\n Cannot withdraw, Insuffecient Balance!.\n";
				cout << "\n Amount to is   : " << Amount;
				cout << "\n Your Balance is: " << Client1.AccountBalance;
			}
		}
		else
		{
			cout << "\n Operation was cancelled.\n";
		}
	}

};

