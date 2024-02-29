#include <iostream>
#include <curl/curl.h>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <lib/byrontools.h>

/*
  AdobePatcher developed in C++.
  (It probably won't work that well right now)
*/

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
  ((std::string *)userp)->append((char *)contents, size * nmemb);
  return size * nmemb;
}

using namespace std;
int main(void)
{
  printf("\x1B[31m [AdobePatcher] \033[0m\t\t");
  printf("\n");

  ofstream hostsCopy("hostsCopy.txt");
  fstream file;
  CURL *curl;
  CURLcode res;
  std::string readBuffer;
  const char *pathToHosts = "C:/Windows/System32/drivers/etc/hosts.txt";
  struct stat sb;

  curl = curl_easy_init();
  if (curl)
  {
    curl_easy_setopt(curl, CURLOPT_URL, "https://raw.githubusercontent.com/ignaciocastro/adobe-is-dumb/main/127.txt");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    hostsCopy << readBuffer << std::endl;
    printf("\x1B[32m [+] Completed adding urls to the copied host file. \033[0m\t\t");
    printf("\n");
  }
  hostsCopy.close();

  printf("\x1B[31m [~] Merging copied and original host files together...  \033[0m\t\t");
  printf("\n");
  // PlaySound("", NULL, SND_FILENAME);

  if (stat(pathToHosts, &sb) == 0)
  {
    cout << "Path to hosts file exists.";
    ifstream ifile("hostsCopy.txt", ios::in);
    ofstream ofile("C:/Windows/System32/drivers/etc/hosts.txt", ios::out | ios::app);

    if (!ifile.is_open())
    {
      cout << "file not found";
    }
    else
    {
      ofile << ifile.rdbuf();
    }

    string word;
    file.open("C:/Windows/System32/drivers/etc/hosts.txt");

    while (file >> word)
    {
      printf("\n");
      printf("\x1B[32m [+] Appending new hosts \033[0m\t\t");
    }
  }
  else
  {
    cout << "The path does not exist.";
    printf("\n");
  }

      printf("\n");
      printf("\x1B[32m [+] Installing other dependencies \033[0m\t\t");
  return 0;
}