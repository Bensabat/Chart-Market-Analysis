#include "data.hh"

bool doubleTop(float n1, float n2, float n3, float n4, float n5) {
    if (n1 < n2 && n1 < n3 && n1 < n4 &&
        n5 < n2 && n5 < n3 && n5 < n4 &&
        n2 > n3 && n4 > n3)
        return true;
    return false;
}

bool doubleBottom(float n1, float n2, float n3, float n4, float n5) {
    if (n1 > n2 && n1 > n3 && n1 > n4 &&
        n5 > n2 && n5 > n3 && n5 > n4 &&
        n2 < n3 && n4 < n3)
        return true;
    return false;
}



std::vector<std::tuple<struct data, struct data, enum Type>> getPatterns(std::vector<struct data> datas) {
    std::vector<std::tuple<struct data, struct data, enum Type>> res;
    for (size_t i = 0; i < datas.size(); i++) {
            if (i+4 < datas.size()) {
                auto d = datas.data();
                float n1 = d[i].value;
                float n2 = d[i + 1].value;
                float n3 = d[i + 2].value;
                float n4 = d[i + 3].value;
                float n5 = d[i + 4].value;
                
                if (doubleTop(n1, n2, n3, n4, n5))
                    res.push_back(std::make_tuple(d[i], d[i + 4], DoubleTop));
                if (doubleBottom(n1, n2, n3, n4, n5))
                    res.push_back(std::make_tuple(d[i], d[i + 4], DoubleBottom));
                
            }
    }
    return res;
}

std::vector<std::tuple<struct data, struct data, enum Type>> getPatternsParallel(std::vector<struct data> datas) {
    std::vector<std::tuple<struct data, struct data, enum Type>> res;
    size_t i;
    #pragma omp parallel for private(i)
    for (i = 0; i < datas.size(); i++) {
            if (i+4 < datas.size()) {
                auto d = datas.data();
                float n1 = d[i].value;
                float n2 = d[i + 1].value;
                float n3 = d[i + 2].value;
                float n4 = d[i + 3].value;
                float n5 = d[i + 4].value;
                
                if (doubleTop(n1, n2, n3, n4, n5))
                    res.push_back(std::make_tuple(d[i], d[i + 4], DoubleTop));
                if (doubleBottom(n1, n2, n3, n4, n5))
                    res.push_back(std::make_tuple(d[i], d[i + 4], DoubleBottom));
                
            }
    }
    return res;
}


void printPattern(std::vector<std::tuple<struct data, struct data, enum Type>> patterns) {
  if (patterns.size() == 0)
    std::cout << "No pattern found.\n";
  else 
  {
    for (size_t i = 0; i < patterns.size(); i++) {
        std::cout << std::get<2>(patterns[i]) << ": du "
                  << std::get<0>(patterns[i]).date << "eme au "
                  << std::get<1>(patterns[i]).date << "eme date " << std::endl;
    }
  }
}


