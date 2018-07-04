#include "simple.hh"
// struct data
// float: value
// int: date

float perpendicularDistance(data p, data first, data last)
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

std::vector<data> simplification(std::vector<data> points)
{
  float epsilon = 0;

  float dmax = 0;
  int index = 0;
  int last_idx = points.size() - 1;

  for (std::size_t t = 0; t != points.size(); ++t)
  {
    float d = perpendicularDistance(points[t], points[0], points[last_idx]);
    if (d > dmax)
    {
      dmax = d;
      index = t;
    }
  }

  if (dmax > epsilon)
  {
    std::vector<data> first_mid = std::vector<data>();
    for (int i = 0; i < index; i++)
      first_mid.push_back(points[i]);
    std::vector<data> res1 = simplification(first_mid);
    first_mid.clear();
    for (int i = index; i < last_idx; i++)
      first_mid.push_back(points[i]);
    std::vector<data> res2 = simplification(first_mid);
    auto res = std::vector<data>();
    for (auto ele : res1)
      res.push_back(ele);
    for (auto ele : res2)
      res.push_back(ele);
    return res;
  }
  return points;
}
