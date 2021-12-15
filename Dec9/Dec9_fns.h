//
// Created by Abbie Currington on 15/12/2021.
//

#ifndef ADVENTOFCODE_DEC9_FNS_H
#define ADVENTOFCODE_DEC9_FNS_H


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>    // std::sort

std::vector<std::vector<int> > extract_and_store_input(std::ifstream &file);
int find_risk_and_set_basins(const std::vector<std::vector<int> > &grid, std::vector<std::vector<int> > &basin_grid,
                            int &num_basins);
int find_low_point(const int &column, const int &row, const std::vector<std::vector<int> >&grid);
std::vector<int> fill_basins(std::vector<std::vector<int> > &basin_grid, const int &num_basins);

int find_max_basins(std::vector<int> &basin_size);

#endif //ADVENTOFCODE_DEC9_FNS_H
