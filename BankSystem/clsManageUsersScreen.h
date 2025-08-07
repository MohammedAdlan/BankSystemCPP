#pragma once
#include <iomanip>
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsFindUserScreen.h"
#include "clsUsersListScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"

class clsManageUsersScreen : protected clsScreen
{
private:
	enum enManageUsersOptions
	{
		eListUsers = 1, eAddNewUser,
		eDeleteUser, eUpdateUser,
		eFindUser, eShowMainMenueScreen
	};

	static short _ReadManageUserstMenueOption()
	{
		cout << setw(37) << left << "" << "   Choose what do you want to do: [1 to 6]: ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6);
		return Choice;
	}

	static void _GoBackToManageUsersMenue()
	{
		cout << setw(37) << left << "" << "\n  Press any press to go back to main menue ...";
		system("pause>0");
		ShowManageUsersMenue();
	}

	static void _ShowListUsersScreen()
	{
		clsUsersListScreen::ShowUsersList();
	}

	static void _ShowAddNewUsersScreen()
	{
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUserScreen()
	{
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserScreen()
	{
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _PerformManageUsersMenueOptions(enManageUsersOptions ManageUsersMenueOption)
	{
		switch (ManageUsersMenueOption)
		{
		case eListUsers:
			system("cls");
			_ShowListUsersScreen();
			_GoBackToManageUsersMenue();
			break;

		case eAddNewUser:
			system("cls");
			_ShowAddNewUsersScreen();
			_GoBackToManageUsersMenue();
			break;

		case eDeleteUser:
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenue();
			break;

		case eUpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersMenue();
			break;

		case eFindUser:
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenue();
			break;

		case eShowMainMenueScreen:
		{

		}
		}
	}

public:

	static void ShowManageUsersMenue()
	{
		if (!CheckAccessRights(clsUser::pManageUsers))
			return; //this will exit the function and it will not execute.

		system("cls");
		DrawScreenHeader("\t\t    Manage Users Screen");

		cout << setw(37) << left << "" << "   ------------------------------------------\n";
		cout << setw(37) << left << "" << "\t\t    Manage Users Menue\n";
		cout << setw(37) << left << "" << "   ------------------------------------------\n";
		cout << setw(37) << left << "" << "\t  [1] List Users.\n";
		cout << setw(37) << left << "" << "\t  [2] Add New User.\n";
		cout << setw(37) << left << "" << "\t  [3] Delete User.\n";
		cout << setw(37) << left << "" << "\t  [4] Update User.\n";
		cout << setw(37) << left << "" << "\t  [5] Find User.\n";
		cout << setw(37) << left << "" << "\t  [6] Main Menue.\n";
		cout << setw(37) << left << "" << "   ------------------------------------------\n";
		_PerformManageUsersMenueOptions((enManageUsersOptions)_ReadManageUserstMenueOption());
	}
};

