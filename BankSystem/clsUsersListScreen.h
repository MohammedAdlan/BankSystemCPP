#pragma once
#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "clsScreen.h"

class clsUsersListScreen : protected clsScreen
{
private:

	static void _PirntUserRecordLine(clsUser User)
	{
		cout << setw(8) << left << "" << "| " << left << setw(15) << User.UserName;
		cout << "| " << left << setw(25) << User.FullName();
		cout << "| " << left << setw(12) << User.Phone;
		cout << "| " << left << setw(20) << User.Email;
		cout << "| " << left << setw(10) << User.Password;
		cout << "| " << left << setw(12) << User.Permissions;
	}

public:

	static void  ShowUsersList()
	{
		vector <clsUser> vUsers = clsUser::GetUsersList();

		string SubTitle = "\t\t[" + to_string(vUsers.size()) + "] User(s)";
		DrawScreenHeader("\t\t    Users List Screen", SubTitle);

		cout << setw(8) << left << "" << "\n\t_________________________________________________________________________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(15) << "User Name";
		cout << "| " << left << setw(25) << "Full Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(12) << "Permissions";
		cout << setw(8) << left << "" << "\n\t_________________________________________________________________________________________________________" << endl;

		if (vUsers.size() == 0)
			cout << "\n\t\t\t\t\t No Users Available In the System!";
		else
			for (clsUser& User : vUsers)
			{
				cout << endl;
				_PirntUserRecordLine(User);
			}

		cout << setw(1) << left << "" << "\n\t_________________________________________________________________________________________________________\n";

	}
};


