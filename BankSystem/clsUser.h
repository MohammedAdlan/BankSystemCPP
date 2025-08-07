#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"
#include "clsUtil.h"


using namespace std;


class clsUser : public clsPerson
{
private:
    enum  enMode { EmptyMode = 0, UpdateMode, AddNewMode };

    enMode _Mode;
    string _UserName = "";
    string _Password = "";
    int _Permissions = 0;
    bool _MarkForDelete = false;

    struct stLoginRegisterRecord;
    static stLoginRegisterRecord _ConvertLoginRegisterToRecord(string Line, string Separator = "#//#")
    {
        stLoginRegisterRecord LoginRegisterRecord;
        vector <string> LoginRegisterDataLine = clsString::Split(Line, Separator);

        LoginRegisterRecord.DateTime = LoginRegisterDataLine[0];
        LoginRegisterRecord.UserName = LoginRegisterDataLine[1];
        LoginRegisterRecord.Password = clsUtil::DecryptText(LoginRegisterDataLine[2]);
        LoginRegisterRecord.Permissions = stoi(LoginRegisterDataLine[3]);

        return LoginRegisterRecord;
    }

    string _PrepareLogInRecord(string Separator = "#//#")
    {
        string stLoginRecord = "";
        stLoginRecord += clsDate::GetSystemDateTimeString() + Separator;
        stLoginRecord += UserName + Separator;
        //here we encrypt store the encrypted Password not the real one.
        stLoginRecord += clsUtil::EncryptText(Password) + Separator;
        stLoginRecord += to_string(Permissions);

        return stLoginRecord;
    }

    static clsUser _ConvertLineToUserObject(string Line, string Separator = "#//#")
    {
        vector <string> vUserData;
        vUserData = clsString::Split(Line, Separator);

        return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
            vUserData[3], vUserData[4], clsUtil::DecryptText(vUserData[5]), stoi(vUserData[6]));
    }

    static string _ConvertUserObjectToLine(clsUser U, string Separator = "#//#")
    {
        string stUserRecord = "";
        stUserRecord += U.FirstName + Separator;
        stUserRecord += U.LastName + Separator;
        stUserRecord += U.Email + Separator;
        stUserRecord += U.Phone + Separator;

        stUserRecord += U.UserName + Separator;
        //here we encrypt store the encrypted Password not the real one.
        stUserRecord += clsUtil::EncryptText(U.Password) + Separator;
        stUserRecord += to_string(U.Permissions);

        return stUserRecord;
    }

    static vector <clsUser> _LoadUsersDataFromFile()
    {
        vector <clsUser> vUsers;

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line = "";

            while (getline(MyFile, Line))
            {
                vUsers.push_back(_ConvertLineToUserObject(Line));
            }
            MyFile.close();
        }
        return vUsers;
    }

    static void _SaveUsersDataToFile(vector <clsUser> vUsers)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out); //overwrite

        if (MyFile.is_open())
        {
            for (clsUser U : vUsers)
            {
                if (U.MarkForDelete() == false)
                    MyFile << _ConvertUserObjectToLine(U) << "\n";
            }
            MyFile.close();
        }

    }

    void _Update()
    {
        vector <clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.UserName == UserName)
            {
                U = *this;
                break;
            }
        }
        _SaveUsersDataToFile(_vUsers);
    }

    void _AddNew()
    {
        _AddDataLineToFile(_ConvertUserObjectToLine(*this));
    }

    void _AddDataLineToFile(string stDataLine)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out | ios::app);
        if (MyFile.is_open())
        {
            MyFile << stDataLine << "\n";
            MyFile.close();
        }
    }

    static clsUser _GetEmptyUserObject()
    {
        return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

public:

    struct stLoginRegisterRecord
    {
        string DateTime = "";
        string UserName = "";
        string Password = "";
        int  Permissions = 0;
    };

    clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone,
        string UserName, string Password, int Permissions) :
        clsPerson(FirstName, LastName, Email, Phone)
    {
        _Mode = Mode;
        _UserName = UserName;
        _Password = Password;
        _Permissions = Permissions;
    }

    bool IsEmpty()
    {
        return (_Mode == EmptyMode);
    }

    bool MarkForDelete()
    {
        return _MarkForDelete;
    }

    void SetUserName(string UserName)
    {
        _UserName = UserName;
    }

    string GetUserName()
    {
        return _UserName;
    }

    __declspec(property(get = GetUserName, put = SetUserName)) string UserName;

    void SetPassword(string Password)
    {
        _Password = Password;
    }

    string GetPassword()
    {
        return _Password;
    }

    __declspec(property(get = GetPassword, put = SetPassword)) string Password;

    void SetPermissions(int Permissions)
    {
        _Permissions = Permissions;
    }

    int GetPermissions()
    {
        return _Permissions;
    }

    __declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;



    /* void Print()
     {
         cout << "\n\n User Card:";
         cout << "\n ---------------------------------";
         cout << "\n First Name: " << FirstName;
         cout << "\n Last Name : " << LastName;
         cout << "\n Full Name : " << FullName();
         cout << "\n Email     : " << Email;
         cout << "\n Phone     : " << Phone;
         cout << "\n UserName   : " << _UserName;
         cout << "\n Password   : " << _Password;
         cout << "\n Permissions: " << Permissions;
         cout << "\n ---------------------------------" << endl;
     }*/

    static clsUser Find(string UserName)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line = "";
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLineToUserObject(Line);

                if (User.UserName == UserName)
                {
                    MyFile.close();
                    return User;
                }
            }
            MyFile.close();
        }
        return _GetEmptyUserObject();
    }

    static clsUser Find(string UserName, string Password)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line = "";
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLineToUserObject(Line);

                if (User.UserName == UserName && User.Password == Password)
                {
                    MyFile.close();
                    return User;
                }
            }
            MyFile.close();
        }
        return _GetEmptyUserObject();
    }

    enum  enSaveResults { svFaildEmptyObject = 0, svSucceeded, svFaildUserExist };

    enSaveResults Save()
    {
        switch (_Mode)
        {
        case clsUser::EmptyMode:
        {
            if (IsEmpty())
                return enSaveResults::svFaildEmptyObject;

            break;
        }
        case clsUser::UpdateMode:
        {
            _Update();
            return enSaveResults::svSucceeded;
            break;
        }
        case clsUser::AddNewMode:
        {
            //this will add new recordto file or databse
            if (clsUser::IsUserExist(_UserName))
            {
                return clsUser::svFaildUserExist;
            }
            else
            {
                _AddNew();
                _Mode = UpdateMode; //we need to set the mode to update after add new
                return clsUser::svSucceeded;
            }
            break;
        }
        }
    }

    static bool IsUserExist(string UserName)
    {
        clsUser User = clsUser::Find(UserName);
        return (!User.IsEmpty());
    }

    bool Delete()
    {
        vector <clsUser> _vClients = _LoadUsersDataFromFile();
        for (clsUser& C : _vClients)
        {
            if (C.UserName == _UserName)
            {
                C._MarkForDelete = true;
                break;
            }
        }

        _SaveUsersDataToFile(_vClients);

        *this = _GetEmptyUserObject();

        return true;
    }

    static clsUser GedAddNewUserObject(string UserName)
    {
        return clsUser(AddNewMode, "", "", "", "", UserName, "", 0);
    }

    static vector <clsUser> GetUsersList()
    {
        return _LoadUsersDataFromFile();
    }

    enum enPermissions
    {
        eAll = -1, pListClients = 1, pAddNewClient = 2,
        pDeleteClient = 4, pUpdateClient = 8,
        pFindClient = 16, pTransactions = 32,
        pManageUsers = 64, pShowLoginRegister = 128, pCurrencyExchange = 256
    };

    bool CheckAccessPermission(enPermissions Permission)
    {
        if (this->Permissions == eAll)
            return true;

        if ((Permission & this->Permissions) == Permission)
            return true;
        else
            return false;
    }

    void RegisterLogin()
    {
        string stDateLine = _PrepareLogInRecord();
        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::out | ios::app);
        if (MyFile.is_open())
        {
            MyFile << stDateLine << "\n";
            MyFile.close();
        }
    }

    static vector <stLoginRegisterRecord> GetLoginRegisterList()
    {
        vector <stLoginRegisterRecord> vLoginRegisterRecord;

        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line = "";

            while (getline(MyFile, Line))
            {
                vLoginRegisterRecord.push_back(_ConvertLoginRegisterToRecord(Line));
            }
            MyFile.close();
        }
        return vLoginRegisterRecord;
    }
};

