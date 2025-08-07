#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsFindClientScreen : protected clsScreen
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
	static void ShowFindClientScreen()
	{
		if (!CheckAccessRights(clsUser::pFindClient))
			return; //this will exit the function and it will not execute.

		DrawScreenHeader("\t\t    Find Client Screen");

		string AccountNumber = "";

		cout << "\n Please Enter AccountNumber: ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\n AccountNumber is Not found, Choose another One: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		if (!Client1.IsEmpty())
			_PrintClient(Client1);
		else
			cout << "\nClient was Not Found.";


	}
};

