#pragma once
#include "ProvinceCodes.h"
#include <curl/curl.h>
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;
class HTTPParser {
private:
  ProvinceCode _code;
  CURL *curl_;
  static size_t writeCallback(char *ptr, size_t size, size_t nmemb,
                              string *data) {
    data->append(ptr, size * nmemb);
    return size * nmemb;
  }

public:
  HTTPParser();
  HTTPParser(ProvinceCode code);
  string fetchData();
};
