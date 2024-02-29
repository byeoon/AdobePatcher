#include <iostream>
#include <curl/curl.h>
#include <fstream>
#include <string>

/*
Test project
*/

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

using namespace std;
int main(void) {
   printf("\x1B[31m [Adobe] \033[0m\t\t");
   
   ofstream MyFile("filename.txt");
   MyFile << "eeeeee";
   MyFile.close();
   // PlaySound("", NULL, SND_FILENAME);

  CURL *curl;
  CURLcode res;
  std::string readBuffer;

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "http://www.google.com");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    std::cout << readBuffer << std::endl;
  }
  
   return 0;
}