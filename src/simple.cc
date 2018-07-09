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

  auto res = num / dem;
  if (std::isinf(res) || !std::isfinite(res))
    return 0;
  return res;
}

std::vector<data> simplification(std::vector<data> points)
{
  // Hard to find a correct epsilon because it depends too much
  // on each dataset. Can compute by machine learning an average of each action
  float epsilon = 100;

  float dmax = 0;
  std::size_t index = 0;
  std::size_t last_idx = points.size() - 1;

  // Find the point with the max distance
  for (std::size_t t = 1; t <  points.size() - 1; ++t)
  {
    float d = 0;
    if (points.size() > 0)
      d = perpendicularDistance(points[t], points[0], points[last_idx]);
    if (d > dmax)
    {
      dmax = d;
      index = t;
    }
  }

  // If max dist is greater than epsilon, than simplify
  if (dmax > epsilon)
  {
    std::vector<data> first_mid = std::vector<data>();
    // Get the first half
    std::cout << "SIZE POINTS: " << points.size() << "\n";
    for (std::size_t i = 0; i < points.size() && i < index; i++)
    {
      std::cout << i << "\n";
      first_mid.push_back(points[i]);
    }

    // Recursive call
    std::vector<data> res1 = simplification(first_mid);

    // Get the second half
    first_mid.clear();
    for (std::size_t i = index; i < points.size() - 1&& i < last_idx; i++)
      first_mid.push_back(points[i]);

    // Recursive call
    std::vector<data> res2 = simplification(first_mid);

    // Build the result list
    auto res = std::vector<data>();
    for (auto ele : res1)
      res.push_back(ele);
    res.pop_back();
    for (auto ele : res2)
      res.push_back(ele);
    return res;
  }

  // If the distance is not greater, then return all points
  return points;
}
