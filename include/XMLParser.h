#pragma once
#include "HTTPParser.h"
#include "tinyxml2.h"
#include <string>

using namespace tinyxml2;
using namespace std;

class XMLParser : public HTTPParser {
private:
    XMLDocument _doc;
    string _code;
    string _data;

public:

  XMLParser();
  XMLParser(string code, string cityCode);

  void parseXML();


};
