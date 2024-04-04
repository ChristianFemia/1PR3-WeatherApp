#pragma once
#include <string>
#include <iostream>
#include <stdexcept>
#include "bcrypt.h"
#include <fstream>
#include <sstream>
using namespace std;

class UserData
{
protected:
    string m_username;
    string m_password; 
    string m_cityCode;
    string m_provinceCode;
    bool m_auth = false;

public:
    UserData();
    string getUsername();
    void setUsername(string username);
    bool entryExists(string entry);
    bool login(string username, string hashedPassword);
    void registerUser(string username, string password, string cityCode, string provinceCode);

};


