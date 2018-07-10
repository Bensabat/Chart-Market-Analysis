#pragma once


void printPattern(std::vector<std::tuple<struct data, struct data,  struct data, struct data, struct data, enum Type>> patterns);
std::vector<std::tuple<struct data, struct data,  struct data, struct data, struct data, enum Type>> getPatterns(std::vector<struct data> datas);
std::vector<std::tuple<struct data, struct data,  struct data, struct data, struct data, enum Type>> getPatternsParallel(std::vector<struct data> datas);
