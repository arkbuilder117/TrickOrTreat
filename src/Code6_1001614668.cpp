// Authors: Noah Walker 1001614668
// Class: CSE 1325 Object-Oriented Programming Fall 2019
// Assignment: Assignment 6

// IMPORTS
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include <ctime>
#include "House.h"
#include "CandyHouse.h"
#include "ToothbrushHouse.h"
#include "TrickOrTreater.h"

using namespace std;

// Retrives file names from command line parameters.
// Stores names in functions arguments passed by reference
void get_command_line_params(int argc, char *argv[], string &tot, string &house, string &candy)
{
  if (argc < 4)
  {
    throw invalid_argument("Missing command line parameters – - Usage : input^filename output^filename");
  }

  tot = argv[1];
  house = argv[2];
  candy = argv[3];
}

int main(int argc, char *argv[])
{
  srand(time(NULL));

  string tot;
  string house;
  string candy;
  try
  {
    get_command_line_params(argc, argv, tot, house, candy);
  }
  catch (invalid_argument &say)
  {
    cout << "Exiting program - \n\n";
    cout << say.what() << "\n\n";
    exit(1);
  }
  ifstream TrickOrTreaterFile(tot);
  ifstream HouseFile(house);
  ifstream CandyFile(candy);

  // Creating a map from contents of CandyFile
  map<int, std::string> CandyRanking;
  char str[100];
  string line;
  char *token;
  string name;

  if (CandyFile.is_open())
  {
    while (getline(CandyFile, line))
    {
      strcpy(str, line.c_str());
      token = strtok(str, "|");
      name = token;
      token = strtok(NULL, "|");
      CandyRanking.insert(make_pair(stoi(token), name));
    }
    CandyFile.close();
  }

  // Creating a vector of pointers to House objects
  // House objects can either be CandyHouse or ToothBrushHouse
  vector<House *> HouseList;
  ostringstream header;
  int random;
  string HeaderSpaces = "";
  if (HouseFile.is_open())
  {
    while (getline(HouseFile, line))
    {
      for (int i = 0; i < 11 - HeaderSpaces.length(); i++)
      {
        header << " ";
      }
      header << line;
      HeaderSpaces = line;
      random = rand() % 2 + 1;
      if (random == 1)
      {
        HouseList.push_back(new CandyHouse{line, CandyRanking});
      }
      else
      {
        HouseList.push_back(new ToothbrushHouse{line, CandyRanking});
      }
    }
    HouseFile.close();
    header << "\n";
  }
  else
  {
    cout << "The file did not open\n";
  }

  // Creating a vector of TrickOrTreater objects
  vector<TrickOrTreater> TOTs;
  if (TrickOrTreaterFile.is_open())
  {
    while (getline(TrickOrTreaterFile, line))
    {
      TOTs.push_back(TrickOrTreater{line, HouseList});
    }
    TrickOrTreaterFile.close();
  }

  // Starting thread attributes on each TrickOrTreater object
  for (auto &stuff : TOTs)
  {
    stuff.startThread();
  }

  // Printing position of each TrickOrTreater object to the command line
  // Continues until each TrickOrTreater has finished
  string spaces;
  while (TrickOrTreater::ImDone != TOTs.size())
  {
    for (int k = 0; k < 34; k++)
    {
      cout << "\n";
    }
    cout << header.str();
    for (auto &q : TOTs)
    {
      for (int i = 0; i <= 10 - q.getName().length(); i++)
      {
        spaces = spaces + " ";
      }
      cout << q.getPath() << q.getName() << "\n";
      spaces = "";
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }

  // Ending threads and printing contents from each TrickOrTreater object
  for (auto &TOT : TOTs)
  {
    TOT.joinThread();
  }
  for (auto &bucket : TOTs)
  {
    cout << bucket;
  }

  // Freeing memory and calling destrutor from each House object in HouseList
  for (auto &House : HouseList)
  {
    delete House;
  }
}
