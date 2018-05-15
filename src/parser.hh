#pragma once

#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <locale>
#include <algorithm>
#include <experimental/filesystem>
#include "data.hh"

namespace Parser
{
    int dateToInt(std::string s);
    int parser(day &day, std::string path);
    void parse_days(std::vector<day> days);    
}