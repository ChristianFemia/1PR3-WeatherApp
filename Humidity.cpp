#include "include/Humidity.h"
using namespace std;
Humidity::Humidity() {};
Humidity::~Humidity() {};
Humidity::Humidity(string location):Statistics(location) {}
void Humidity::display() {
    double const PM25 = 6;
    double const c1 = -1.78469475556; //Coeficientes used for the calculation of the heat index.
    double const c2 = 1.61139411;
    double const c3 = 2.33854944;
    double const c4 = -0.14611605;
    double const c5 = -0.012308094;
    double const c6 = -0.016424827;
    double const c7 = 0.002211732;
    double const c8 = 0.00072546;
    double const c9 = -0.000003582;

    string l;
                
                cout << "HUMIDITY FACTORS" << endl;
                cout << "________________" << endl;

                cout << "Visibilaty: " << (17.3 + 0.09 * present_temp - 0.11 * present_humidity + 0.34 * wind_speed * PM25) << "%" << endl;//performing the calculation for the visibilaty.

                cout << "Heat Index: " << (c1 + (c2 * present_temp) + (c3 * (present_humidity/100)) + (c4 * present_temp * (present_humidity/100)) + (c5 * pow(present_temp, 2)) + (c6 * pow((present_humidity/100), 2)) + (c7 * pow(present_temp, 2) * (present_humidity/100)) + (c8 * (present_humidity/100) * pow((present_humidity/100), 2)) + (c9 * pow(present_temp, 2) * pow((present_humidity/100), 2))) << " degrees celsius" << endl;//performing the calculation for the heat index.
            }
