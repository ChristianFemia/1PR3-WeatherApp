#include "include/UserData.h"

UserData::UserData() {

  m_username = "";
  m_password = "";
  m_cityCode = "";
  m_provinceCode = "";
  m_auth = false;
}

string UserData::getUsername() {
  return m_auth
             ? m_username
             : throw std::invalid_argument("Error! User is not authenticated!"); //Throw an error if the user is not authenticated
}

void UserData::setUsername(string username) {
  if (m_auth) {
    m_username = username;
  } else {
    throw std::invalid_argument("Error! User is not authenticated!"); //Throw an error if the user is not authenticated
  }
}


bool UserData::entryExists(string newEntry) {
  ifstream file("UserData.txt");
  string line;
  while (getline(file, line)) {
    stringstream ss(line); // use a string stream to see if the entry exists
    string entry;
    while (ss >> entry) { // Space is used as delimiter
      if (entry == newEntry) { //Check to see if the entries match, if they do, return true
        file.close();
        return true;
      }
    }
  }
  file.close();
  return false;
}


bool UserData::login(string username, string hashedPassword) {
  fstream file("UserData.txt");
  string line;

  while (getline(file, line)) {
    string storedUsername, storedHashedPassword, storedCityCode, storedProvinceCode; // Local Variables for the stored values
    istringstream iss(line); //Use a string stream to store each line of the file
    if (iss >> storedUsername >> storedHashedPassword >> storedCityCode >> storedProvinceCode) { // Check to see if something is present AND save to the variables
      if (storedUsername == username && bcrypt::validatePassword(hashedPassword, storedHashedPassword)) { // IF the username and password match, then set the auth to true and save the variables
          hashedPassword = storedHashedPassword;
          m_cityCode = storedCityCode;
          m_provinceCode = storedProvinceCode;
          m_auth = true;
          return true; // Username found, and password was correct
        }
    }
  }

  return false; // Username not found Or password was incorrect
}

void UserData::registerUser(string username, string password, string cityCode, string provinceCode) {
  string name = username;
  string hash = bcrypt::generateHash(password);
  

  fstream stream("UserData.txt", fstream::app);
  string line;
  if (!entryExists(name)) { //Check to ensure the entry does not exist already
    stream << name << " " << hash << " " << cityCode << " " << provinceCode << "\n"; //save to file
    stream.close(); //close file
  } else {
    throw std::invalid_argument("Error! User already exists!");
  }
}


