#include <iostream>
#include <curl/curl.h>
#include <fstream>
#pragma comment(lib, "winmm.lib")
#include <string>
#include <cpr/cpr.h>

/*
Test project
*/
using namespace std;
using namespace cpr;
int main() {
   printf("\x1B[31m [Adobe] \033[0m\t\t");
   
   ofstream MyFile("filename.txt");
   MyFile << "eeeeee";
   MyFile.close();
   // PlaySound("", NULL, SND_FILENAME);
   auto r = Get(Url{ "https://raw.githubusercontent.com/" });
    cout << r.text << endl;
   return 0;
}