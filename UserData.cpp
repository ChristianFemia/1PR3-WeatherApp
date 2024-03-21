#include "include/UserData.h"

UserData::UserData() {

  m_username = "";
  m_password = "";
  m_auth = false;
}

string UserData::getUsername() {
  return m_auth
             ? m_username
             : throw std::invalid_argument("Error! User is not authenticated!");
}
void UserData::setUsername(string username) {
  if (m_auth) {
    m_username = username;
  } else {
    throw std::invalid_argument("Error! User is not authenticated!");
  }
}

bool UserData::entryExists(string newEntry) {
  ifstream file("UserData.txt");
  string line;
  while (getline(file, line)) {
    stringstream ss(line);
    string entry;
    while (ss >> entry) { // Space is used as delimiter
      if (entry == newEntry) {
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
    string storedUsername, storedHashedPassword;
    istringstream iss(line);
    if (iss >> storedUsername >> storedHashedPassword) {
      if (storedUsername == username && bcrypt::validatePassword(hashedPassword, storedHashedPassword) {
          hashedPassword = storedHashedPassword;
          m_auth = true;
          return true; // Username found, and password was correct
        }
    }
  }

  return false; // Username not found Or password was incorrect
}

void UserData::registerUser(string username, string password) {
  string name = username;
  string hash = bcrypt::generateHash(password);

  fstream stream("UserData.txt", fstream::app);
  string line;
  if (!entryExists(name)) {
    stream << name << " " << hash << "\n";
    stream.close();
  } else {
    throw std::invalid_argument("Error! User already exists!");
  }
}


