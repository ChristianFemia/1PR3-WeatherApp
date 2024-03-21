#include "include/HTTPParser.h"

HTTPParser::HTTPParser(){
    throw std::invalid_argument("Class requires parameters");
}

HTTPParser::HTTPParser(ProvinceCode code){
  
  curl_global_init(CURL_GLOBAL_DEFAULT);
  curl_ = curl_easy_init();
  if (!curl_) {
      cerr << "Failed to initialize Libcurl." << endl;
      throw runtime_error("Failed to initialize Libcurl.");
  }
}

string HTTPParser::fetchData(string url) {
    string data;
    curl_easy_setopt(curl_, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl_, CURLOPT_WRITEFUNCTION, writeCallback);
    curl_easy_setopt(curl_, CURLOPT_WRITEDATA, &data);
    CURLcode res = curl_easy_perform(curl_);
    if (res != CURLE_OK) {
        cerr << "Failed to fetch URL: " << curl_easy_strerror(res) << endl;
        throw runtime_error("Failed to fetch URL.");
    }
    return data;
}
