#pragma once

#include <vector>
#include <cmath>
#include <iterator>

#include "data.hh"


float perpendicularDistance(struct data p, struct data first, struct data last);
std::vector<struct data> simplification(std::vector<struct data> points);
