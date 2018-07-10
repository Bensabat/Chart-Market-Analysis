#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>
#include "parser.hh"
#include "simple.hh"
#include "pattern.hh"
#include "plotter.hh"

int main()
{
	// Vector containing all the days data
	std::vector<day> days;
	parse_days(days);

	// Plotting days
	//plot_days(days);
    
	double start=0.0, stop=0.0;
    start = omp_get_wtime();
	for (auto day : days) 
    {
		std::cout << "Processing file: " << day.name << "\n";
		auto simplified_day = day;
		simplified_day.data_vect = simplification(day.data_vect);
		
		if (simplified_day.data_vect.size() == 0)
			std::cout << "BAD SIMPLIFICATION\n"; 
		auto patterns = getPatterns(simplified_day.data_vect);
		printPattern(patterns);
  	}

	stop = omp_get_wtime();
    std::cout << "Time in sequential: " << stop-start << std::endl;

	start = omp_get_wtime();
	for (auto day : days) 
  	{
		auto simplified_day = day;
		simplified_day.data_vect = simplification(day.data_vect);
		auto patterns = getPatternsParallel(simplified_day.data_vect);
		//printPattern(patterns);
  	}
    stop = omp_get_wtime();
    std::cout << "Time in parallel: " << stop-start << std::endl;

	return 0;
}
