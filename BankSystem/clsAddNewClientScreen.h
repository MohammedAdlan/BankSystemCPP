#pragma once
#include "clsScreen.h"
#include "Global.h"

class clsAddNewClientScreen : protected clsScreen
{
private:

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

	static void ShowAddNewClientScreen()
	{
		if (!CheckAccessRights(clsUser::pAddNewClient))
			return; //this will exit the function and it will not execute.

		DrawScreenHeader("\t\t    Add New Screen");
		string AccountNumber = "";

		cout << "\n Please Enter AccountNumber: ";
		AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\n AccountNumber is Not found, Choose another One: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient NewClient = clsBankClient::GedAddNewClientObject(AccountNumber);

		cout << " ----------------------------------- \n";

		_ReadClientInfo(NewClient);

		clsBankClient::enSaveResults SaveResult;

		SaveResult = NewClient.Save();

		switch (SaveResult)
		{
		case clsBankClient::svSucceeded:
		{
			cout << "\n Account Added Successfully.\n";
			_PrintClient(NewClient);
			break;
		}
		case clsBankClient::svFaildEmptyObject:
		{
			cout << "\n Error Account was not saved because it's empty.\n";
			break;
		}
		case clsBankClient::svFaildAccountNumberExist:
		{
			cout << "\n Error Account was not saved because Account Number Exist.\n";
			break;
		}
		}

	}

};

