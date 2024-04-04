#pragma once

#include <curl/curl.h>
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;
class HTTPParser {
private:
  string _code;
  string _cityCode;
  CURL *curl_;
  static size_t writeCallback(char *ptr, size_t size, size_t nmemb,
                              string *data) {
    data->append(ptr, size * nmemb);
    return size * nmemb;
  }

public:
  HTTPParser();
  void setCityCode(string cityCode){ _cityCode = cityCode; }
  void setProvinceCode(string provinceCode) { _code = provinceCode; }
  string fetchData();
};
