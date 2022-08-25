// Authors: Noah Walker 1001614668
// Class: CSE 1325 Object-Oriented Programming Fall 2019
// Assignment: Assignment 6

// ToothBrushHouse class header file
#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <mutex>
#include <thread>
#include "House.h"

#ifndef _TBHOUSE_H
#define _TBHOUSE_H

class ToothbrushHouse : public House
{

public:
	ToothbrushHouse(std::string, std::map<int, std::string>);
	~ToothbrushHouse();
	std::string ringDoorbell(std::ostringstream &);
};

#endif
