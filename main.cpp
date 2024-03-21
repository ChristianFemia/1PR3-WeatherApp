#include <iostream>
#include "include/HTTPParser.h"
#include "include/UserData.h"

using namespace std;

int main() {
  string username, password;
    UserData data;
    cout << "Enter a username: " << endl;
    cin >> username;
    cout << "Enter a password: " << endl;
    cin >> password;
    if(data.login(username, password)){
        cout << "Login successful!" << endl;
    } else {
      cout << "Login failed!" << endl;
    }
    return 0;
}