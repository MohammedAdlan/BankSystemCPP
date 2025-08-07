#pragma once
#include "clsScreen.h"

class clsTransferScreen : protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\n\n Client Card:";
		cout << "\n _________________________________\n";
		cout << "\n Full Name : " << Client.FullName();
		cout << "\n Acc NO    : " << Client.AccountNumber();
		cout << "\n Balance   : " << Client.AccountBalance;
		cout << "\n _________________________________" << endl;
	}

	static string _ReadAccountNumber(string Message = "\n Please Enter AccountNumber: ")
	{
		string AccountNumber = "";
		cout << Message;
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\n AccountNumber is Not found, Choose another One: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}

	static float _ReadAmount(clsBankClient SourceClient, string Message = "\n\n Please Enter Transfer Amount: ")
	{
		float Amount = 0;
		cout << Message;
		Amount = clsInputValidate::ReadPositiveDblNumber();
		while (Amount > SourceClient.AccountBalance)
		{
			cout << "Amoun Excedds the availble Balance! Enter again: ";
			Amount = clsInputValidate::ReadPositiveDblNumber();
		}
		return Amount;
	}

public:

	static void ShowTransferScreen()
	{
		DrawScreenHeader("\t\t    Transfer Screen");


		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());
		_PrintClient(SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());
		_PrintClient(DestinationClient);

		float Amount = _ReadAmount(SourceClient);

		char Answer = 'n';
		cout << "\n\n Are you  sure you want to perform this Operation? [Y/N]: ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient, CurrentUser.UserName))
			{
				cout << "\n\n ------------------------- \n\n";
				cout << " Transfer  Successfully.";
				cout << "\n\n ------------------------- \n";

			}
			else
			{
				cout << "\n\n ------------------------- \n\n";
				cout << " Transfer  UnSuccessfully.";
				cout << "\n\n ------------------------- \n";
			}


		}
		else
		{
			cout << "\n Operation was cancelled.\n";
		}
		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);
	}
};

