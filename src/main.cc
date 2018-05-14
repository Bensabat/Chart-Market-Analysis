#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>
#include "parser.hh"

int main()
{
	std::vector<data> day;
	Parser::parser(day);

	std::vector<data>::iterator it;
	for(it = day.begin(); it != day.end(); it++)
	{
		std::cout << it->value << std::endl;
	}
	
	return 0;
}
