#Noah Walker 1001614668
SRC1 = src/Code6_1001614668.cpp
SRC2 = src/TrickOrTreater.cpp
SRC3 = src/House.cpp
SRC4 = src/CandyHouse.cpp
SRC5 = src/ToothbrushHouse.cpp
OBJ1 = $(SRC1:.cpp=.o)
OBJ2 = $(SRC2:.cpp=.o)
OBJ3 = $(SRC3:.cpp=.o)
OBJ4 = $(SRC4:.cpp=.o)
OBJ5 = $(SRC5:.cpp=.o)
# EXE = $(SRC1:.cpp=.e)
EXE = build.e

CFLAGS = -g -std=c++11 -pthread

HFILES = src/House.h src/TrickOrTreater.h src/CandyHouse.h src/ToothbrushHouse.h

all : $(EXE)

$(EXE): $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5)
	g++ $(CFLAGS) $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5) -o $(EXE)

$(OBJ1) : $(SRC1) $(HFILES)
	g++ -c $(CFLAGS) $(SRC1) -o $(OBJ1)

$(OBJ2) : $(SRC2) $(HFILES)
	g++ -c $(CFLAGS) $(SRC2) -o $(OBJ2)

$(OBJ3) : $(SRC3) $(HFILES)
	g++ -c $(CFLAGS) $(SRC3) -o $(OBJ3)

$(OBJ4) : $(SRC4) $(HFILES)
	g++ -c $(CFLAGS) $(SRC4) -o $(OBJ4)

$(OBJ5) : $(SRC5) $(HFILES)
	g++ -c $(CFLAGS) $(SRC5) -o $(OBJ5)
