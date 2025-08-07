#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsUpdateClientScreen : protected clsScreen
{
	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << " Enter First Name     : ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << " Enter Last Name      : ";
		Client.LastName = clsInputValidate::ReadString();

		cout << " Enter Email          : ";
		Client.Email = clsInputValidate::ReadString();

		cout << " Enter Phone          : ";
		Client.Phone = clsInputValidate::ReadString();

		cout << " Enter Pin Code       : ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << " Enter Account Balance: ";
		Client.AccountBalance = clsInputValidate::ReadFloatNumber();

		cout << " -----------------------------------\n";
	}

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

	static void ShowUpdateClientScreen()
	{
		if (!CheckAccessRights(clsUser::pUpdateClient))
			return; //this will exit the function and it will not execute.

		DrawScreenHeader("\t\t   Update Client Screen");

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

		cout << " ------------------------------------ \n";

		_ReadClientInfo(Client1);

		clsBankClient::enSaveResults SaveResult;

		SaveResult = Client1.Save();

		switch (SaveResult)
		{
		case clsBankClient::svSucceeded:
		{
			cout << "\n Account Updated Successfully.\n";
			_PrintClient(Client1);
			break;
		}
		case clsBankClient::svFaildEmptyObject:
		{
			cout << "\n Error Account was not saved because it's empty.\n";
			break;
		}
		};
	}

};

