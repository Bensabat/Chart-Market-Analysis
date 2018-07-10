#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <sys/stat.h>
#include "parser.hh"
#include "simple.hh"
#include "pattern.hh"
#include "plotter.hh"


void save_days(std::vector<day> days)
{
	for (auto day : days)
	{
		std::string day_name_path = day.name;
		std::string day_name = day_name_path.substr(12, day_name_path.size() - 12);

		mkdir("./formated-resources", S_IRWXU);
		std::ofstream outfile ("./formated-resources/" + day_name);

		std::vector<data> data_vect = day.data_vect;
		for (auto data : data_vect)
		{
			outfile << data.date << " " << data.value << std::endl;
		}
	}
}

int main()
{
	// Vector containing all the days data
	std::vector<day> days;
	parse_days(days);

	// Save on disk the formatted resources
	save_days(days);

	double start=0.0, stop=0.0;
    start = omp_get_wtime();
	for (auto day : days) 
    {
		std::cout << "Processing file: " << day.name << "\n";

		std::string day_name_path = day.name;
		std::string day_name = day_name_path.substr(12, day_name_path.size() - 12);

		auto simplified_day = day;
		simplified_day.data_vect = simplification(day.data_vect);

		if (simplified_day.data_vect.size() == 0)
			std::cout << "BAD SIMPLIFICATION\n";
 
		auto patterns = getPatterns(simplified_day.data_vect);
		printPattern(patterns, day_name);
  	}

	stop = omp_get_wtime();
    std::cout << "Time in sequential: " << stop-start << std::endl;

	start = omp_get_wtime();
	for (auto day : days) 
  	{
		auto simplified_day = day;
		simplified_day.data_vect = simplification(day.data_vect);
		auto patterns = getPatternsParallel(simplified_day.data_vect);
		//printPattern(patterns, day_name);
  	}
    stop = omp_get_wtime();
    std::cout << "Time in parallel: " << stop-start << std::endl;

	return 0;
}
