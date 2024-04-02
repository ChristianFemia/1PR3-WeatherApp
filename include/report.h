#pragma once
#include "XMLParser.h"

class Report {
private:
    XMLParser& parser;

public:
    explicit Report(XMLParser& xmlParser);
    string generateBasicReport();
    string generateComplexReport();
};
