#include "include/DisplayDriverLogin.h"

DisplayDriverLogin::DisplayDriverLogin() : UserData(){}

void DisplayDriverLogin::loginUser(){
  string username, password;
  cout << "-----------------------" << endl;
  cout << "Please enter a username: " << endl;
  cin >> username;
  cout << "Please enter a password: " << endl;
  cin >> password;
  if (login(username, password)) {
    cout << "Successful Login! " << endl;
  } else {
    cout << "Invalid Username or Password! " << endl;
  }
}

void DisplayDriverLogin::registerUser() {
  string username, password, cityCode, provinceCode;
  cout << "-----------------------" << endl;
  cout << "Please enter a username: " << endl;
  cin >> username;
  cout << "Please enter a password: " << endl;
  cin >> password;

  cout << "Please enter a unique city code that you wish to search for. (Such "
          "as s0000549 for Hamilton, Ontario)."
       << endl;
  cin >> cityCode;

  cout << "Please enter a unique province code for the city you just entered. Pleaes note, this is not the province name, but the 2 letter abbreviation. (Such as ON for Ontario)." << endl;
    cin >> provinceCode;
  if(Utility::checkRegex(provinceCode)){ 
    UserData::registerUser(username, password, cityCode, provinceCode); 
  } 
  else { cout << "Invalid province code! Please try again." << endl; }
}

//Logout method used to, well logout.
void DisplayDriverLogin::logout(){
  cout << "-----------------------" << endl;
  cout << "Goodbye!" << endl; 
  cout << "-----------------------" << endl;
}


//Function used to loop through the menu options
void DisplayDriverLogin::loginMenu(){
  cout << "-----------------------" << endl;
  cout << "Welcome to 1PR3-WeatherReport! Please select one of the "
          "following options: "
       << endl;
  cout << "1. Login" << endl;
  cout << "2. Register" << endl;
  cout << "3. Exit" << endl;
  cout << "-----------------------" << endl;
  int choice;
  cin >> choice;
  if(choice == 1){ loginUser(); }
  else if(choice == 2){ registerUser(); }
  else if(choice == 3){ logout(); }
  else { cout << "Invalid Option, please try again." << endl; }
}