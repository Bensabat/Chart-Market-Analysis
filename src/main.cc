#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>
#include "parser.hh"
#include "simple.hh"
#include "pattern.hh"

int main()
{
	// Vector containing all the days data
	std::vector<day> days;
	parse_days(days);	
  
	for (auto day : days) 
  {
    auto simplified_day = day;
    simplified_day.data_vect = simplification(day.data_vect);
    auto patterns = getPatterns(simplified_day.data_vect);
    printPattern(patterns);
  }

	return 0;
}
