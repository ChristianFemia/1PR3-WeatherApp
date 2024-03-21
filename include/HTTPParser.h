#pragma once
#include <string>
#include <stdexcept>
#include <curl/curl.h>
#include <iostream>
#include "ProvinceCodes.h"
using namespace std;
class HTTPParser
{
private:
  CURL* curl_;
  static size_t writeCallback(char* ptr, size_t size, size_t nmemb, string* data) {
      data->append(ptr, size * nmemb);
      return size * nmemb;
  }

public:
    HTTPParser();
    HTTPParser(ProvinceCode code);
    string fetchData(string url);

};
