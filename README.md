# TrickOrTreat
This repository contains the TrickOrTreat project done by Noah Walker for CSE 1325 Object-Oriented Programming taught by Donna French in the fall 2019 semester at the University of Texas at Arlington.

`Steps to run:`
---
1. Use make to create the exectable "build.e"
2. Run the executable with TOT.txt HOUSES.txt CANDY.txt. These are the input files.

`Description:`
---
Simulates a user going to different types of houses one at a time.
A list of users travel on a path to multiple houses. Houses can be either a CandyHouse or ToothBrushHouse which determines what item it gives a user. When a user reaches a house, it places a mutex on that House then releases the mutex after it has gotten candy or a toothbrush from the House and places it in its bucket. After all users have finished, the contents of each user's bucket is displayed.
