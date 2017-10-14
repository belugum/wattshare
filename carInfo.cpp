//
// car.cpp for car in /home/shiba/shiba/rendu/hackathon/wattshare
// 
// Made by shiba
// Login   <zita.cheng@epitech.eu>
// 
// Started on  Sat Oct 14 18:10:10 2017 shiba
// Last update Sat Oct 14 20:58:34 2017 shiba
//

#include "carInfo.hpp"

static size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp)
{
  ((std::string*)userp)->append((char*)contents, size * nmemb);
  return (size * nmemb);
}

carInfo::carInfo()
{
  std::string	key;
  std::string	url;
  std::string	str;
  std::ifstream	myfile("key");

  key = "";
  if (myfile.is_open())
    {
      while (getline(myfile, key));
      myfile.close();
    }
  str = "Ocp-Apim-Subscription-Key: " + key;
  this->curl = curl_easy_init();
  this->chunk = curl_slist_append(chunk, str.c_str());
  curl_easy_setopt(this->curl, CURLOPT_HTTPHEADER, this->chunk);
  url = "https://renaultcafeapi.litmus.cloud/hoc/cars/ZoeGrise/data";
  if(this->curl)
    {
      curl_easy_setopt(this->curl, CURLOPT_URL, url.c_str());
      curl_easy_setopt(this->curl, CURLOPT_WRITEFUNCTION, write_callback);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, &this->readBuffer);
      curl_easy_perform(this->curl);
      curl_easy_cleanup(this->curl);
    }
}

carInfo::~carInfo()
{
  
}

float	carInfo::getSoc()
{
  return (0);
}
