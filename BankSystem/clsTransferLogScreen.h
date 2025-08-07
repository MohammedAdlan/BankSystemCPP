#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"

class clsTransferLogScreen : protected clsScreen
{
private:
	static void _PirntTransfersLogRecordLine(clsBankClient::stTransferLogRecord TransferLogRecord)
	{
		cout << setw(8) << left << "" << "| " << left << setw(22) << TransferLogRecord.DateTime;
		cout << "| " << left << setw(10) << TransferLogRecord.srcAccountNumber;
		cout << "| " << left << setw(10) << TransferLogRecord.destAccountNumber;
		cout << "| " << left << setw(11) << TransferLogRecord.Amount;
		cout << "| " << left << setw(11) << TransferLogRecord.srcBalanceAfter;
		cout << "| " << left << setw(11) << TransferLogRecord.destBalanceAfter;
		cout << "| " << left << setw(20) << TransferLogRecord.UserName;
	}

public:
	static void  ShowTransferLogScreen()
	{
		vector <clsBankClient::stTransferLogRecord> vTransferLogRecord = clsBankClient::GetTrasfersLogList();

		string SubTitle = "\t\t[" + to_string(vTransferLogRecord.size()) + "] Record(s)";
		DrawScreenHeader("\t\t  Transfers Log List Screen", SubTitle);

		cout << setw(8) << left << "" << "\n\t_________________________________________________________________________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(22) << "DateTime";
		cout << "| " << left << setw(10) << "S.Acc NO";
		cout << "| " << left << setw(10) << "D.Acc NO";
		cout << "| " << left << setw(11) << "Amount";
		cout << "| " << left << setw(11) << "S.Balance";
		cout << "| " << left << setw(11) << "D.Balance";
		cout << "| " << left << setw(20) << "User Name";
		cout << setw(1) << left << "" << "\n\t_________________________________________________________________________________________________________" << endl;

		if (vTransferLogRecord.size() == 0)
			cout << "\n\t\t\t\t\t No Transfers Available In the System!";
		else
			for (clsBankClient::stTransferLogRecord& Record : vTransferLogRecord)
			{
				cout << endl;
				_PirntTransfersLogRecordLine(Record);

			}

		cout << setw(1) << left << "" << "\n\t_________________________________________________________________________________________________________\n";

	}
};

