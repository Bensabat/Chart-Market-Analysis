#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>
#include "parser.hh"

int main()
{
	// Vector containing all the days data
	std::vector<day> days;
	parse_days(days);	
	
	return 0;
}
