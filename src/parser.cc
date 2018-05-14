#include "parser.hh"

namespace Parser
{

int parser(std::vector<data> day)
{
	std::ifstream infile("./ressources/CAC40_2018-05-14.txt");

	std::string s1, s2, s3, s4, s5, s6, s7, s8;

	if (!(infile >> s1 >> s2 >> s3 >> s4 >> s5 >> s6 >> s7))
	{
		std::cout << "Error: could not read first line, abort. \n";
	}

	while (infile >> s1 >> s2 >> s3 >> s4 >> s5 >> s6 >> s7 >> s8)
	{
		// successfully extracted one line, data is in s1, ..., s8.
		//std::cout << s1 << s2 << s3 << s4 << s5 << s6 << s7 << s8 << std::endl;
        data point = data();
        point.value = strtof((s2).c_str(), 0);
        point.date = 1;
        day.push_back(point);
	}

    return 0;
}

}