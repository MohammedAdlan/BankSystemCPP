#pragma once
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsDeleteUserScreen : protected clsScreen
{
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
	static void ShowDeleteUserScreen()
	{

		DrawScreenHeader("\t\t    Delete User Screen");
		string UserName = "";

		cout << "\n Please Enter UserName: ";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\n UserName is Not found, Choose another One: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);
		_PrintUser(User);

		char Answer = 'n';
		cout << "\n\n Are you  sure you want to delete this user? [Y/N]: ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (User.Delete())
			{
				cout << "\n User Deleted Successfully.\n";
				_PrintUser(User);
			}
			else
			{
				cout << "\n Error User was not Deleted.\n";
			}
		}

	}
};

