/*#include <iostream>
#include "include/Alerts.h"
#include "include/NormalAlerts.h"
#include "include/DangerousAlerts.h"
#include <fstream>

int main()
{

  int num;

  cout << "Please enter 1 to display alerts... " << endl;
  cin >> num;

  if (num == 1) {

    const int NUM = 2;

    Alerts* Noti[NUM];

    ifstream infile("Data.txt");
    if (infile.is_open()) {

      string location;
      double temp;
      double wind;
      double rain;
      double pressure;
      double humidity;

      infile >> location >> temp >> wind >> pressure >> humidity >> rain;
      Noti[0] = new NormalAlerts(location, temp, wind);
      Noti[1] = new DangerousAlerts(location, temp, wind, pressure, humidity, rain);

    }

    else {

      cout << "Unable to open file." << endl;

    }
    infile.close();

    for (int i = 0; i < NUM; i++) {

      Noti[i]->displayAlert();
    }
  }

}*/