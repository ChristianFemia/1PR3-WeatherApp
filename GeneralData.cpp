#include "include/GeneralData.h"
GeneralData::GeneralData() {};
GeneralData::~GeneralData() {};
GeneralData::GeneralData(string location) : Statistics(location){}
void GeneralData::display() {
  //General Data Print out
        cout << "TODAYS UPDATE " << m_location << endl;//Displaying Data from the file.
        cout << "______________" << endl;
        cout << "Todays temperature is: " << present_temp << " degres celcius" << endl;
        cout << "Todays humidity is: " << present_humidity << "%" << endl;
        cout << "The chance of percipitation is: " << presipitation << "%" << endl << endl;

        cout << "HIGHS & LOWS" << endl;
        cout << "____________" << endl;
        cout << "The warmest temperature this week was: " << warmest_temp << " degres celcius" << endl;
        cout << "The coldest temperature this week was: " << coldest_temp << " degres celcius" << endl;
      }
