//
// car.hpp for hpp in /home/shiba/shiba/rendu/hackathon/wattshare
// 
// Made by shiba
// Login   <zita.cheng@epitech.eu>
// 
// Started on  Sat Oct 14 18:09:20 2017 shiba
// Last update Sun Oct 15 09:28:33 2017 shiba
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
  nlohmann::json        data;
  carInfo();
  
public:
  carInfo(std::string);
  ~carInfo();
  float			getSoc();
  int			getRemainingTime();
};
