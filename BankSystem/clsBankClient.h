#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
using namespace std;

class clsBankClient : public clsPerson
{
private:
    enum  enMode { EmptyMode = 0, UpdateMode, AddNewMode };
    enMode _Mode;

    string _AccountNumber = "";
    string _PinCode = "";
    float _AccountBalance = 0;
    bool _MarkForDelete = false;

    static clsBankClient _ConvertLineClientToObject(string Line, string Separator = "#//#")
    {
        vector <string> vClientData;
        vClientData = clsString::Split(Line, Separator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
    }

    static string _ConvertClientObjectToLine(clsBankClient C, string Separator = "#//#")
    {
        string stClientRecord = "";
        stClientRecord += C.FirstName + Separator;
        stClientRecord += C.LastName + Separator;
        stClientRecord += C.Email + Separator;
        stClientRecord += C.Phone + Separator;
        stClientRecord += C.AccountNumber() + Separator;
        stClientRecord += C.PinCode + Separator;
        stClientRecord += to_string(C.AccountBalance);

        return stClientRecord;
    }

    static vector <clsBankClient> _LoadClientDataFromFile()
    {
        vector <clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line = "";

            while (getline(MyFile, Line))
            {
                vClients.push_back(_ConvertLineClientToObject(Line));
            }
            MyFile.close();
        }
        return vClients;
    }

    static void _SaveClientDataToFile(vector <clsBankClient> vClients)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out);

        if (MyFile.is_open())
        {
            for (clsBankClient C : vClients)
            {
                if (C.MarkForDelete() == false)
                    MyFile << _ConvertClientObjectToLine(C) << "\n";
            }
            MyFile.close();
        }

    }

    void _Update()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }
        }
        _SaveClientDataToFile(_vClients);
    }

    void _AddNew()
    {
        _AddDataLineToFile(_ConvertClientObjectToLine(*this));
    }

    void _AddDataLineToFile(string stDataLine)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);
        if (MyFile.is_open())
        {
            MyFile << stDataLine << "\n";
            MyFile.close();
        }
    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    struct  stTransferLogRecord;
    static stTransferLogRecord _ConvertTransferRegisterToRecord(string Line, string Separator = "#//#")
    {
        stTransferLogRecord TransferLogRecord;
        vector <string> vTransferLogRecordLine = clsString::Split(Line, Separator);

        TransferLogRecord.DateTime = vTransferLogRecordLine[0];
        TransferLogRecord.srcAccountNumber = vTransferLogRecordLine[1];
        TransferLogRecord.destAccountNumber = vTransferLogRecordLine[2];
        TransferLogRecord.Amount = stoi(vTransferLogRecordLine[3]);
        TransferLogRecord.srcBalanceAfter = stoi(vTransferLogRecordLine[4]);
        TransferLogRecord.destBalanceAfter = stoi(vTransferLogRecordLine[5]);
        TransferLogRecord.UserName = vTransferLogRecordLine[6];

        return TransferLogRecord;
    }

    string _PrepareTransferLogInRecord(float Amount, clsBankClient DestinationClient, string UserName, string Separator = "#//#")
    {
        string TransferLogRecord = "";
        TransferLogRecord += clsDate::GetSystemDateTimeString() + Separator;
        TransferLogRecord += AccountNumber() + Separator;
        TransferLogRecord += DestinationClient.AccountNumber() + Separator;
        TransferLogRecord += to_string(Amount) + Separator;
        TransferLogRecord += to_string(AccountBalance) + Separator;
        TransferLogRecord += to_string(DestinationClient.AccountBalance) + Separator;
        TransferLogRecord += UserName;

        return TransferLogRecord;
    }

    void _RegisterTransferLog(float Amount, clsBankClient DestinationClient, string UserName)
    {
        string stDateLine = _PrepareTransferLogInRecord(Amount, DestinationClient, UserName);
        fstream MyFile;
        MyFile.open("TransferLog.txt", ios::out | ios::app);
        if (MyFile.is_open())
        {
            MyFile << stDateLine << "\n";
            MyFile.close();
        }
    }

public:

    struct stTransferLogRecord
    {
        string DateTime = "";
        string UserName = "";
        string srcAccountNumber = "";
        string destAccountNumber = "";
        float  Amount = 0;
        float  srcBalanceAfter = 0;
        float  destBalanceAfter = 0;
    };


    clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone,
        string AccountNumber, string PinCode, float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone)
    {
        _Mode = Mode;
        _PinCode = PinCode;
        _AccountNumber = AccountNumber;
        _AccountBalance = AccountBalance;
    }

    bool IsEmpty()
    {
        return (_Mode == EmptyMode);
    }

    bool MarkForDelete()
    {
        return _MarkForDelete;
    }

    //Read Only Property
    string AccountNumber()
    {
        return _AccountNumber;
    }

    //Property Set
    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    //Property Get
    string GetPinCode()
    {
        return _PinCode;
    }

    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    //Property Set
    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    //Property Get
    float GetAccountBalance()
    {
        return _AccountBalance;
    }

    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

    /*void Print()
    {
        cout << "\n\n Client Card:";
        cout << "\n ---------------------------------";
        cout << "\n Acc NO    : " << _AccountNumber;
        cout << "\n First Name: " << FirstName;
        cout << "\n Last Name : " << LastName;
        cout << "\n Full Name : " << FullName();
        cout << "\n Email     : " << Email;
        cout << "\n Phone     : " << Phone;
        cout << "\n Password  : " << _PinCode;
        cout << "\n Balance   : " << _AccountBalance;
        cout << "\n ---------------------------------" << endl;
    }*/

    static clsBankClient Find(string AccountNumber)
    {
        //string FileName = "Clients.txt";
        //vector <clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line = "";
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLineClientToObject(Line);

                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }
                //vClients.push_back(Client);
            }
            MyFile.close();
        }
        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {
        //string FileName = "Clients.txt";
        //vector <clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line = "";
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLineClientToObject(Line);

                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }
                //vClients.push_back(Client);
            }
            MyFile.close();
        }
        return _GetEmptyClientObject();
    }

    enum  enSaveResults { svFaildEmptyObject = 0, svSucceeded, svFaildAccountNumberExist };

    enSaveResults Save()
    {
        switch (_Mode)
        {
        case clsBankClient::EmptyMode:
        {
            if (IsEmpty())
                return enSaveResults::svFaildEmptyObject;

            break;
        }
        case clsBankClient::UpdateMode:
        {
            _Update();
            return enSaveResults::svSucceeded;
            break;
        }
        case clsBankClient::AddNewMode:
        {
            //this will add new recordto file or databse
            if (clsBankClient::IsClientExist(_AccountNumber))
            {
                return clsBankClient::svFaildAccountNumberExist;
            }
            else
            {
                _AddNew();
                _Mode = UpdateMode; //we need to set the mode to update after add new
                return clsBankClient::svSucceeded;
            }
            break;
        }
        }
    }

    static bool IsClientExist(string AccountNumber)
    {
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        return (!Client1.IsEmpty());
    }

    bool Delete()
    {
        vector <clsBankClient> _vClients = _LoadClientDataFromFile();
        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == _AccountNumber)
            {
                C._MarkForDelete = true;
                break;
            }
        }

        _SaveClientDataToFile(_vClients);

        *this = _GetEmptyClientObject();

        return true;
    }

    static clsBankClient GedAddNewClientObject(string AccountNumber)
    {
        return clsBankClient(AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }

    static vector <clsBankClient> GetClientsList()
    {
        return _LoadClientDataFromFile();
    }

    void Deposit(double Amount)
    {
        _AccountBalance += Amount;
        Save();
    }

    bool Withdraw(double Amount)
    {
        if (Amount > _AccountBalance)
            return false;
        else
        {
            _AccountBalance -= Amount;
            Save();
            return true;
        }
    }

    static double GetTotalBalance()
    {
        double TotalBalance = 0;
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        for (clsBankClient& Client : vClients)
        {
            TotalBalance += Client.AccountBalance;
        }
        return TotalBalance;
    }

    bool Transfer(float Amount, clsBankClient& DestinationClient, string UserName)
    {
        if (Amount > _AccountBalance)
            return false;
        else
        {
            Withdraw(Amount);
            DestinationClient.Deposit(Amount);
            _RegisterTransferLog(Amount, DestinationClient, UserName);
            return true;
        }
    }

    static vector <stTransferLogRecord> GetTrasfersLogList()
    {
        vector <stTransferLogRecord> vTransferLogRecord;

        fstream MyFile;
        MyFile.open("TransferLog.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line = "";

            while (getline(MyFile, Line))
            {
                vTransferLogRecord.push_back(_ConvertTransferRegisterToRecord(Line));
            }
            MyFile.close();
        }
        return vTransferLogRecord;
    }

};

