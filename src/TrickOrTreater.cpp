// Noah Walker 1001614668
#include <iostream>
#include <string>
#include <thread>
#include <map>
#include <chrono>
#include <vector>
#include <sstream>
#include <mutex>

#include "House.h"
#include "TrickOrTreater.h"

int TrickOrTreater::ImDone = 0;

TrickOrTreater::TrickOrTreater(std::string str, std::vector<House *> HouseList)
    : name(str), ListOfHouses(HouseList)
{
}

std::string TrickOrTreater::getName()
{
  return name;
}

void TrickOrTreater::startThread()
{
  TOTThreadPtr = new std::thread(&TrickOrTreater::GoTrickOrTreating, this);
}

void TrickOrTreater::joinThread()
{
  this->TOTThreadPtr->join();
  delete this->TOTThreadPtr;
}

void TrickOrTreater::GoTrickOrTreating()
{
  int speed;
  std::string candy;
  for (auto i : ListOfHouses)
  {
    speed = rand() % 500 + 1;
    Walk(speed);
    candy = i->ringDoorbell(path);
    Bucket[candy]++;
  }
  ImDone++;
}

void TrickOrTreater::Walk(int speed)
{
  for (int i = 1; i < 11; i++)
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(speed));
    path << ".";
  }
}

std::string TrickOrTreater::getPath()
{
  return path.str();
}

std::ostream &operator<<(std::ostream &output, TrickOrTreater &tot)
{
  output << tot.name << "'s' - ";
  for (auto i : tot.Bucket)
  {
    output << i.second << " " << i.first << ",";
  }
  output << "\n";
  return output;
}
