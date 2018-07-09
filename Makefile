CXX      = g++
CXXFLAGS = -fopenmp -Werror -Wextra -Wall -pedantic -std=c++14 -O2

SRC  = src/main.cc		\
			 src/parser.cc	\
			 src/simple.cc	\
			 src/pattern.cc
EXEC = detect_pattern

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(EXEC)

rm:
	rm $(EXEC) $(EXEC2)
