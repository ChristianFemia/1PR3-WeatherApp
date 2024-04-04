#include "include/WeatherReport.h"
WeatherReport::WeatherReport() : XMLParser(){};

    void WeatherReport::generateComplexReport() {
        tinyxml2::XMLDocument doc;
        doc.Parse(fetchData().c_str());

        cout << "Detailed Weekly Weather Forecast Report\n";
        cout << "Location: " << doc.FirstChildElement("siteData")->FirstChildElement("location")->FirstChildElement("name")->GetText() << endl;
        cout << "---------------------------------------\n";
      XMLElement* forecast = doc.FirstChildElement("siteData")->FirstChildElement("forecastGroup")->FirstChildElement("forecast");
          string period = forecast->FirstChildElement("period")->GetText();
            string summary = forecast->FirstChildElement("textSummary")->GetText();
            string temperatures = forecast->FirstChildElement("temperatures")->FirstChildElement("textSummary")->GetText();
             string winds = doc.FirstChildElement("siteData")->FirstChildElement("currentConditions")->FirstChildElement("wind")->FirstChildElement("speed")->GetText();
            string humidity = "Relative Humidity: " + string(forecast->FirstChildElement("relativeHumidity")->GetText()) + "%";
            // UV index might be missing in some forecasts, so check if it exists first
            const char* uvText = forecast->FirstChildElement("uv") ? forecast->FirstChildElement("uv")->FirstChildElement("textSummary")->GetText() : "Not available";
            string uvIndex = "UV Index: " + string(uvText);

            cout << period << ":\n";
            cout << summary << "\n";
            cout << temperatures << "\n";
            cout << "Wind gusts up to: " << winds << " km/h" << "\n";
            cout << humidity << "\n";
            cout << uvIndex << "\n\n";

        // Sun rise and set times
        auto riseSet = doc.FirstChildElement("siteData")->FirstChildElement("riseSet");
        string sunrise = "Sunrise: " + string(riseSet->FirstChildElement("dateTime")->FirstChildElement("textSummary")->GetText());
        string sunset = "Sunset: " + string(riseSet->FirstChildElement("dateTime")->NextSiblingElement("dateTime")->FirstChildElement("textSummary")->GetText());

        cout << sunrise << "\n";
        cout << sunset << "\n";
    }
