#include "include/HTTPParser.h"

HTTPParser::HTTPParser() {
  curl_global_init(CURL_GLOBAL_DEFAULT); //initalize curl, the parsing library
  curl_ = curl_easy_init();
  if (!curl_) {
    cerr << "Failed to initialize Libcurl." << endl;
    throw runtime_error("Failed to initialize Libcurl.");
  }
}

string HTTPParser::fetchData() {
  string url = "https://dd.weather.gc.ca/citypage_weather/xml/" +
               _code + "/" + _cityCode +
               "_e.xml";
  string data;
  curl_easy_setopt(curl_, CURLOPT_URL, url.c_str()); //Open the connect over the internet
  curl_easy_setopt(curl_, CURLOPT_WRITEFUNCTION, writeCallback); //Set the write callback
  curl_easy_setopt(curl_, CURLOPT_WRITEDATA, &data); //Write the data to the string
  CURLcode res = curl_easy_perform(curl_); //Perform the request
  if (res != CURLE_OK) { //If failed, error out.
    cerr << "Failed to fetch URL: " << curl_easy_strerror(res) << endl;
    throw runtime_error("Failed to fetch URL.");
  }
  return data;
}
