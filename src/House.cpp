// Authors: Noah Walker 1001614668
// Class: CSE 1325 Object-Oriented Programming Fall 2019
// Assignment: Assignment 6

// Defining functions in House class
#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <mutex>
#include <thread>
#include <chrono>
#include "House.h"

House::House(std::string name, std::map<int, std::string> Candy)
    : houseName(name), CandyRankingMap(Candy)
{
}

House::~House()
{
  std::cout << "House\n";
}
