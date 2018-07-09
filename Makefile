CXX      = g++
CXXMAC	 = g++-8
CXXFLAGS = -fopenmp -Wextra -Wall -pedantic -std=c++14 -O2

SRC  = src/main.cc		\
			 src/parser.cc	\
			 src/simple.cc	\
			 src/pattern.cc
EXEC = detect_pattern

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(EXEC)

mac:
	$(CXXMAC) $(CXXFLAGS) $(SRC) -o $(EXEC)
rm:
	rm $(EXEC) $(EXEC2)
