#pragma once
#include "clsUser.h"
class clsFindUserScreen : protected clsScreen
{
private:
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
	static void ShowFindUserScreen()
	{
		DrawScreenHeader("\t\t    Find User Screen");
		string UserName = "";

		cout << "\n Please Enter UserName: ";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\n UserName is Not found, Choose another One: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser NewUser = clsUser::Find(UserName);

		if (!NewUser.IsEmpty())
			_PrintUser(NewUser);
		else
			cout << "\nUser was Not Found.";


	}
};

