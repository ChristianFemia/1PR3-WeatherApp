#include "HTTPParser.h"

HTTPParser::HTTPParser(){
    throw std::invalid_argument("Class requires parameters");
}
HTTPParser::HTTPParser(ProvinceCode code){
    _code = code;
    _url = "https://dd.weather.gc.ca/citypage_weather/xml/"+ProvinceCodes::toString(_code)+"/"+"s0000702"+"_e.xml";
    cout << _url;
}

void HTTPParser::callUrl(){
    CURL *curl;
    CURLcode res;

    // Initialize Libcurl
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        // Set the URL to fetch
        curl_easy_setopt(curl, CURLOPT_URL, _url.c_str());

        // Perform the request
        res = curl_easy_perform(curl);
        // Check for errors
        if(res == CURLE_OK) {
            cout << "Success" << endl;
        } else {
            cerr << "Failed to fetch URL: " << curl_easy_strerror(res) << endl;
        }

        // Cleanup Libcurl
        curl_easy_cleanup(curl);
    } else {
        cerr << "Failed to initialize Libcurl." << endl;
    }

    // Cleanup Libcurl global resources
    curl_global_cleanup();

}