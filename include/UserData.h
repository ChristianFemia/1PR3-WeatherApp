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
private: 
  string m_hash;
protected:
    string m_username;
    string m_password; 
    string m_cityCode;
    string m_provinceCode;
    bool m_auth = false;

public:
    UserData(string username, string password);
    UserData();
    string getUsername();
    string getPassword();
    void setUsername(string username);
    void setPassword(string password);
    bool entryExists(string entry);
    bool login(string username, string hashedPassword);
    void registerUser(string username, string password, string cityCode, string provinceCode);

};


