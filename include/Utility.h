//A Utility Class
#pragma once
#include "UserData.h"
#include "XMLParser.h"
#include "Temperature.h"
#include "Humidity.h"
#include "GeneralData.h"
#include "DangerousAlerts.h"
#include "NormalAlerts.h"
#include "WeatherReport.h"
#include "DisplayDriverLogin.h"
#include <regex>
using namespace std;
class Utility {

  public:
   static bool checkRegex(string input){return regex_search(input, regex("\\b(AB|BC|MB|NB|NL|NS|NT|NU|ON|PE|QC|SK|YT)\\b"));} //Using Regular Expressions (Regex) to check if the input is a valid province code.
};