// Noah Walker 1001614668
#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <mutex>
#include <thread>
#include <chrono>
#include "ToothbrushHouse.h"

ToothbrushHouse::ToothbrushHouse(std::string name, std::map<int, std::string> Candy)
    : House{name, Candy}
{
}

ToothbrushHouse::~ToothbrushHouse()
{
  std::cout << "ToothbrushHouse\n";
}

std::string ToothbrushHouse::ringDoorbell(std::ostringstream &path)
{
  door.lock();
  path << "-";
  std::this_thread::sleep_for(std::chrono::seconds(1));
  door.unlock();
  return "TOOTHBRUSH";
  // figure out how to add TOOTHBRUSH to the TrickOrTreater's map
}
