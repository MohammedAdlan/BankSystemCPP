#pragma once
#include <iostream>
#include "clsUser.h"

class clsAddNewUserScreen : protected clsScreen
{
private:

	static short _ReadPermissionsToSet()
	{
		short Permissions = 0;
		char Answer = 'n';

		cout << " Do you want to giv Full Access [Y/N]: ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
			return  -1;


		//cout << "\n Read Permissions: ";
		//cout << "\n -----------------------------\n";
		cout << " Show Cleint List [Y/N]: ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Answer = 'n';
			Permissions += clsUser::pListClients;
		}

		cout << "\n Add New Client   [Y/N]: ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Answer = 'n';
			Permissions += clsUser::pAddNewClient;
		}

		cout << "\n Delete Client    [Y/N]: ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Answer = 'n';
			Permissions += clsUser::pDeleteClient;
		}


		cout << "\n Update Client    [Y/N]: ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Answer = 'n';
			Permissions += clsUser::pUpdateClient;
		}
		cout << "\n Find Client      [Y/N]: ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Answer = 'n';
			Permissions += clsUser::pFindClient;
		}

		cout << "\n Transactions     [Y/N]: ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Answer = 'n';
			Permissions += clsUser::pTransactions;
		}
		cout << "\n Manage User      [Y/N]: ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Answer = 'n';
			Permissions += clsUser::pManageUsers;
		}
		cout << "\n Login Regisetr   [Y/N]: ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Answer = 'n';
			Permissions += clsUser::pShowLoginRegister;
		}
		cout << "\n Currency Exchange [Y/N]: ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Answer = 'n';
			Permissions += clsUser::pCurrencyExchange;
		}
		return Permissions;
	}

	static void _ReadUserInfo(clsUser& User)
	{
		cout << " Enter First Name     : ";
		User.FirstName = clsInputValidate::ReadString();

		cout << " Enter Last Name      : ";
		User.LastName = clsInputValidate::ReadString();

		cout << " Enter Email          : ";
		User.Email = clsInputValidate::ReadString();

		cout << " Enter Phone          : ";
		User.Phone = clsInputValidate::ReadString();

		cout << " Enter Password       : ";
		User.Password = clsInputValidate::ReadString();

		//cout << " Enter Permissions    : ";
		User.Permissions = _ReadPermissionsToSet();

		cout << " -----------------------------------\n";
	}

	static void _PrintUser(clsUser User)
	{
		cout << "\n\n User Card:";
		cout << "\n ---------------------------------";
		cout << "\n First Name : " << User.FirstName;
		cout << "\n Last Name  : " << User.LastName;
		cout << "\n Full Name  : " << User.FullName();
		cout << "\n Email      : " << User.Email;
		cout << "\n Phone      : " << User.Phone;
		cout << "\n UserName   : " << User.UserName;
		cout << "\n Password   : " << User.Password;
		cout << "\n Permissions: " << User.Permissions;
		cout << "\n ---------------------------------" << endl;
	}

public:

	static void ShowAddNewUserScreen()
	{
		DrawScreenHeader("\t\t    Add New User Screen");
		string UserName = "";

		cout << "\n Please Enter UserName: ";
		UserName = clsInputValidate::ReadString();

		while (clsUser::IsUserExist(UserName))
		{
			cout << "\n UserName is Already found, Choose another One: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser NewUser = clsUser::GedAddNewUserObject(UserName);

		cout << " ----------------------------------- \n";

		_ReadUserInfo(NewUser);

		clsUser::enSaveResults SaveResult;

		SaveResult = NewUser.Save();

		switch (SaveResult)
		{
		case clsUser::svSucceeded:
		{
			cout << "\n User Added Successfully.\n";
			_PrintUser(NewUser);
			break;
		}
		case clsUser::svFaildEmptyObject:
		{
			cout << "\n Error User was not saved because it's empty.\n";
			break;
		}
		case clsUser::svFaildUserExist:
		{
			cout << "\n Error User was not saved because UserName is used.\n";
			break;
		}
		}

	}
};

