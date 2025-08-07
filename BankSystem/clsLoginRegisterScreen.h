#pragma once
#include "clsScreen.h"

class clsLoginRegisterScreen : protected clsScreen
{
private:
	static void _PirntLoginRegisterRecordLine(clsUser::stLoginRegisterRecord LoginRegisterRecord)
	{
		cout << setw(8) << left << "" << "| " << left << setw(40) << LoginRegisterRecord.DateTime;
		cout << "| " << left << setw(20) << LoginRegisterRecord.UserName;
		cout << "| " << left << setw(20) << LoginRegisterRecord.Password;
		cout << "| " << left << setw(10) << LoginRegisterRecord.Permissions;
	}

public:

	static void  ShowLoginRegisterScreen()
	{
		if (!CheckAccessRights(clsUser::pShowLoginRegister))
			return; //this will exit the function and it will not continue.


		vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterList();

		string SubTitle = "\t\t[" + to_string(vLoginRegisterRecord.size()) + "] Record(s)";
		DrawScreenHeader("\t\t  Login Register List Screen", SubTitle);

		cout << setw(8) << left << "" << "\n\t_________________________________________________________________________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(40) << "DateTime";
		cout << "| " << left << setw(20) << "User Name";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(10) << "Permissions";
		cout << setw(8) << left << "" << "\n\t_________________________________________________________________________________________________________\n" << endl;

		if (vLoginRegisterRecord.size() == 0)
			cout << "\n\t\t\t\t\t No Logins Available In the System!";
		else
			for (clsUser::stLoginRegisterRecord& Record : vLoginRegisterRecord)
			{
				_PirntLoginRegisterRecordLine(Record);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_________________________________________________________________________________________________________\n";

	}
};

