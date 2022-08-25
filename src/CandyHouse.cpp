// Authors: Noah Walker 1001614668
// Class: CSE 1325 Object-Oriented Programming Fall 2019
// Assignment: Assignment 6

// Defining functions in CandyHouse class
#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <mutex>
#include <thread>
#include <chrono>
#include "CandyHouse.h"

CandyHouse::CandyHouse(std::string name, std::map<int, std::string> Candy)
    : House{name, Candy}
{
}

CandyHouse::~CandyHouse()
{
  std::cout << "CandyHouse\n";
}

std::string CandyHouse::ringDoorbell(std::ostringstream &path)
{
  door.lock();
  path << "+";
  std::this_thread::sleep_for(std::chrono::seconds(3));
  int key = rand() % CandyRankingMap.size() + 1;
  door.unlock();
  return CandyRankingMap.at(key);
}
