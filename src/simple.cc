#include <vector>
#include <cmath>
#include <iterator>

// struct data
// float: value
// int: date

float perpendicularDistance(struct data p, struct data first, struct data last)
{
  float num = (last.value - first.value) * p.date 
              - (last.date - first.date) * p.value
              + last.date * first.value
              - last.value * first.date;
  num = std::abs(num);
  float dem = (last.value - first.value) * (last.value - first.value)
              + (last.date - first.date) * (last.date - last.date);
  dem = std::sqrt(dem);
  return num / dem;
}

std::vector<struct data> simplification(std::vector<struct data> points)
{
  float epsilon = 5;

  float dmax = 0;
  int index = 0;
  int last_idx = point.size() - 1;

  for (auto it : points)
  {
    float d = perpendicularDistance(it, points[0], points[size - 1]);
    if (d > dmax)
    {
      dmax = d;
      index = std::distance(point.begin, it);
    }
  }
  
  if (dmax > epsilon)
  {
    std::vector<struct data> first_mid = std::vector<struct data>();
    for (int i = 0; i < index; i++)
      first_mid.push_back(tmp);
    std::vector<struct data> res1 = simplification(first_mid);
    first_mid.clear();
    for (int i = index; i < last_idx; i++)
      first_mid.push_back(tmp);
    std::vector<struct data> res2 = simplification(first_mid);
    // vector1.insert( vector1.end(), vector2.begin(), vector2.end() );
    return res1.insert(res1.end(), res2.begin(), res2.end());
  }
  else
    return points;
}
