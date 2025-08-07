#pragma once
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "clsUser.h"
#include "Global.h"

class clsLoginScreen : protected clsScreen
{
private:
	static bool _Login()
	{
		short FaildLoginCounter = 0;
		bool LoginFaild = false;
		string Username, Password = "";
		do
		{


			if (LoginFaild)
			{
				FaildLoginCounter++;
				cout << "\n Invalide Username/Password!";
				cout << "\n You have " << (3 - FaildLoginCounter) << " Trials to login.\n\n";
			}

			if (FaildLoginCounter == 3)
			{
				cout << "\n You are Locked afeter 3 faild trials.\n\n";
				return false;
			}

			cout << " Enter Username: ";
			cin >> Username;

			cout << " Enter Password: ";
			cin >> Password;

			CurrentUser = clsUser::Find(Username, Password);

			LoginFaild = CurrentUser.IsEmpty();
		} while (LoginFaild);

		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenue();
		return true;
	}

public:

	static bool ShowLoginScreen()
	{
		system("cls");
		DrawScreenHeader("\t\t      Login Screen");
		return _Login();
	}
};

