#pragma once
#include "HTTPParser.h"
#include "tinyxml2.h"
#include <string>

using namespace tinyxml2;
using namespace std;

class XMLParser : public HTTPParser {
private:
    XMLDocument _doc;
    ProvinceCode _code;
    string _data;

public:

  XMLParser();
  XMLParser(ProvinceCode code, string cityCode);

  void parseXML();


};
