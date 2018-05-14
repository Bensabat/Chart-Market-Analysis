CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -std=c++14 -pedantic -O2
SRC=src/pattern.cc
OBJ=$(SRC:.cc=.o)
EXEC=pattern
all: $(OBJ)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(EXEC)




