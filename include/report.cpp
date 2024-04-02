#include "report.h"
#include <sstream>

Report::Report(XMLParser& xmlParser) : parser(xmlParser) {}

string Report::generateBasicReport() {
    stringstream report;
    XMLElement* root = parser.getRootElement();
    if (root) {
        XMLElement* condition = root->FirstChildElement("currentConditions")->FirstChildElement("condition");
        XMLElement* temperature = root->FirstChildElement("currentConditions")->FirstChildElement("temperature");
        if (condition) report << "Condition: " << condition->GetText() << "\n";
        if (temperature) report << "Temperature: " << temperature->GetText() << temperature->Attribute("units") << "\n";
    }
    return report.str();
}

string Report::generateComplexReport() {
    stringstream report;
    XMLElement* root = parser.getRootElement();
    if (root) {
        XMLElement* forecastGroup = root->FirstChildElement("forecastGroup");
        if (forecastGroup) {
            for (XMLElement* forecast = forecastGroup->FirstChildElement("forecast"); forecast != nullptr; forecast = forecast->NextSiblingElement("forecast")) {
                XMLElement* period = forecast->FirstChildElement("period");
                XMLElement* textSummary = forecast->FirstChildElement("textSummary");
                if (period && textSummary) report << period->GetText() << ": " << textSummary->GetText() << "\n";
            }
        }
    }
    return report.str();
}
