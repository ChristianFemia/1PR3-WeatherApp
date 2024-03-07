#include <iostream>
#include <curl/curl.h>

using namespace std;

int main() {
    CURL *curl;
    CURLcode res;

    // Initialize Libcurl
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        // Set the URL to fetch
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.cs.utexas.edu/~mitra/csFall2010/cs329/lectures/xml/xslplanes.1.xml.txt");

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

    return 0;
}