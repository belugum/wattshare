//
// car.hpp for hpp in /home/shiba/shiba/rendu/hackathon/wattshare
// 
// Made by shiba
// Login   <zita.cheng@epitech.eu>
// 
// Started on  Sat Oct 14 18:09:20 2017 shiba
// Last update Sat Oct 14 19:22:32 2017 shiba
//

#include <iostream>
#include <fstream>
#include <curl/curl.h>
#include "json.hpp"

class			carInfo
{
  CURL			*curl;
  CURLcode		res;
  struct curl_slist	*chunk = NULL;
  std::string		readBuffer;
  nlohmann::json              data;
public:
  carInfo();
  ~carInfo();
  float			getSoc();
};
