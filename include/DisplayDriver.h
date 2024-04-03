#pragma once
#include "Utility.h"

class DisplayDriver : public DisplayDriverLogin {
public:
  DisplayDriver();
  void periodic(); // loop through all of the options.
  void generateReport();
  void generateAlerts();
  void parseXML(bool generateReport);
};
