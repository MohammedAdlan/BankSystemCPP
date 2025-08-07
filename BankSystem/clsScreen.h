#pragma once
#include <iostream>
#include <iomanip>
#include "Global.h"
#include "clsDate.h"
#include "clsUser.h"

using namespace std;

class clsScreen
{
public:
	static void DrawScreenHeader(string Title, string SubTitle = "")
	{
		cout << "\n\n";
		cout << "\t\t\t\t\t__________________________________________ ";
		cout << "\n\n\t\t\t\t" << Title;
		if (SubTitle != "")
			cout << "\n\t\t\t\t\t" << SubTitle;
		cout << "\n\t\t\t\t\t" << "__________________________________________ \n";

		cout << "\n\t\t\t\t\tUser: " << left << setw(20) << CurrentUser.UserName;
		cout << " Date: " << clsDate::DateToString(clsDate());
		cout << endl << endl;
	}

	static bool CheckAccessRights(clsUser::enPermissions Permission)
	{
		if (!CurrentUser.CheckAccessPermission(Permission))
		{
			cout << "\n\n\t\t\t\t\t___________________________________________ ";
			cout << "\n\n\t\t\t\t\t  Access Denied Please Contact Your Admin";
			cout << "\n\t\t\t\t\t" << "___________________________________________ \n\n";
			return false;
		}
		else
			return true;
	}

};

