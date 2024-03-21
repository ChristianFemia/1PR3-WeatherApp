#pragma once
#include "HTTPParser.h"
#include "tinyxml2.h"
using namespace tinyxml2;
class XMLParser : public HTTPParser {
private:
  string _data;
  ProvinceCodes _code;

public:
  XMLParser();
  XMLParser(string data, ProvinceCodes code);
};