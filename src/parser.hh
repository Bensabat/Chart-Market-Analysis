#pragma once

#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <locale>
#include <algorithm>
#include <boost/filesystem.hpp>
#include <iomanip>
#include "data.hh"

int dateToInt(std::string s);
int parser(struct day &day, std::string path);
void parse_days(std::vector<day> days);    
