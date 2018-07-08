CXX      = g++
CXXFLAGS = -Werror -Wextra -Wall -pedantic -std=c++14 -O2

SRC  = src/main.cc src/parser.cc
EXEC = parser

SRC2 =src/pattern.cc
OBJ2 =$(SRC2:.cc=.o)
EXEC2=pattern

all: parser.exe #pattern.exe

parser.exe:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(EXEC)

pattern.exe: $(OBJ2)
	$(CXX) $(CXXFLAGS) $(SRC2) -o $(EXEC2)

rm:
	rm $(EXEC) $(EXEC2)