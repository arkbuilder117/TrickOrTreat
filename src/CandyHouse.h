// Authors: Noah Walker 1001614668
// Class: CSE 1325 Object-Oriented Programming Fall 2019
// Assignment: Assignment 6

// CandyHouse class header file
#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <mutex>
#include <thread>
#include "House.h"

#ifndef _CHOUSE_H
#define _CHOUSE_H

class CandyHouse : public House
{

public:
  CandyHouse(std::string, std::map<int, std::string>);
  ~CandyHouse();
  std::string ringDoorbell(std::ostringstream &);
};

#endif
