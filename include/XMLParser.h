#pragma once
#include "HTTPParser.h"
#include "tinyxml2.h"
#include <string>

using namespace tinyxml2;
using namespace std;

class XMLParser : public HTTPParser {
private:
    string _data;

public:

  XMLParser();

  void parseXML();


};
