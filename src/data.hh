#include <iostream>
#include <tuple>
#include <vector>

struct data {
  float value;  // ex: 5538.2
  int date;     // ex: 32520 (-> 09h02)
};

struct day {
    std::vector<data> data_vect; // vector containing dots for 1 day
    std::string name;            // ex: CAC40
    std::string date;            // ex: 2018-05-14
};

enum Type {
    DoubleTop,
    DoubleBottom
};
