#include "include/DisplayDriver.h"
DisplayDriver::DisplayDriver() : DisplayDriverLogin(){};

void DisplayDriver::parseXML(bool generateReport){
  WeatherReport parser;
  cout << "-----------------------" << endl;
  cout << "Please select from one of the following options: " << endl;
  cout << "1. Obtain Weather Data for city: " << m_cityCode << endl;
  cout << "2. Obtain Weather Data for a specific city" << endl;
  cout << "3. Exit. " << endl;
  cout << "-----------------------" << endl;

  int choice;
  cin >> choice;

  if (choice == 1) { 
    parser.setCityCode(m_cityCode); 
    parser.setProvinceCode(m_provinceCode); 
  } else if (choice == 2) {
    string cityCode, provinceCode;
    cout << "Please enter a city code that you wish to search for. (Such as s0000549 for Hamiltion") << endl;
    cin >> cityCode;
    cout << "Please enter a unique province code for the city you just entered. Pleaes note, this is not the province name, but the 2 letter abbreviation. (Such as ON for Ontario)." << endl;
    cin >> provinceCode;
    if(Utility::checkRegex(provinceCode)){
      parser.setCityCode(cityCode);
      parser.setProvinceCode(provinceCode);
    } else { cout << "Invalid province code! Please try again." << endl; }
  }
  if(generateReport){parser.generateComplexReport(); }
  else {parser.parseXML();}
  
}

void DisplayDriver::generateReport() {
  int choice;
  parseXML(false);
  cout << "-----------------------" << endl;
  cout << "Please select from one of the following reports to generate: " << endl;
  cout << "1. Temperature Report " << m_cityCode << endl;
  cout << "2. Humidity" << endl;
  cout << "3. General Data Report" << endl;
  cout << "3. Exit. " << endl;
  cout << "-----------------------" << endl;

  cin >> choice; 

  if(choice == 1){Temperature temp(m_cityCode); temp.display();}
  else if(choice == 2){Humidity humididty(m_cityCode); humididty.display();}  
  else if (choice == 3){GeneralData general(m_cityCode); general.display();}
}


void DisplayDriver::generateAlerts(){
   parseXML(false);
   Alerts* Noti[2];
   Noti[0] = new NormalAlerts();
   Noti[1] = new DangerousAlerts();
   for(int i = 0; i<2; i++){
     Noti[i]->displayAlert();
   }
}


void DisplayDriver::periodic() {
  bool open = true;
  while (open) {
    if (!m_auth) { loginMenu(); } 
    else {
      cout << "-----------------------" << endl;
      cout << "Please enter your selection." << endl;
      cout << "1. Basic Weather Report" << endl;
      cout << "2. Complex Weather Report" << endl;
      cout << "3. Alerts in your area Report" << endl;
      cout << "4. Exit" << endl;
      cout << "-----------------------" << endl;
      int choice;
      cin >> choice;
      if(choice == 1){ generateReport(); }
      else if (choice == 2) {parseXML(true); }
      else if (choice == 3) {generateAlerts(); }
      else if (choice == 4) { logout(); open = false; }
      else { cout << "Invalid Option, please try again." << endl; }
    }
  }
}
