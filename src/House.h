// Authors: Noah Walker 1001614668
// Class: CSE 1325 Object-Oriented Programming Fall 2019
// Assignment: Assignment 6

// House class header file
#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <mutex>
#include <thread>

#ifndef _HOUSE_H
#define _HOUSE_H

class House
{
public:
	House(std::string, std::map<int, std::string>);
	virtual std::string ringDoorbell(std::ostringstream &) = 0;
	virtual ~House();

protected:
	std::string houseName;
	std::mutex door;
	std::map<int, std::string> CandyRankingMap;
};

#endif
