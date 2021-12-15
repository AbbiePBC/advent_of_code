//
// Created by Abbie Currington on 15/12/2021.
//

#include "Dec9_fns.h"


std::vector<std::vector<int> > extract_and_store_input(std::ifstream &file){

    std::vector<std::vector<int> > grid;
    std::string line;
    while ( getline (file,line) ){
        std::vector<int> row;
        for (int i = 0; i < line.size(); i ++){
            row.push_back(line[i] - '0');
        }
        grid.push_back(row);
    }
    return grid;
}

int find_low_point(const int &column, const int &row, const std::vector<std::vector<int> >&grid){
    int current = grid[row][column];
    if (column != 0 && grid[row][column-1] <= current){
        return 0;
    }
    if (column != grid[0].size() -1&& grid[row][column+1] <= current){
        return 0;
    }
    if (row != 0 && grid[row-1][column] <= current){
        return 0;
    }
    if (row != grid.size() -1 && grid[row+1][column] <= current){
        return 0;
    }
    return current + 1;
}


std::vector<int > fill_basins(std::vector<std::vector<int> > &basin_grid, const int &num_basins){
    std::vector<int> basin_size (num_basins + 1,1); // num_basins is initialised to 0 so off by one. first int here should not change
    bool all_filled = true;
    while (true){
        all_filled = true;
        for (int row = 0; row < basin_grid.size(); row ++) {
            for (int column = 0; column < basin_grid[0].size(); column++) {
                if (basin_grid[row][column] ==0){
                    all_filled = false;
                }
                if (column+1 != basin_grid[0].size()){
                    if (basin_grid[row][column] == 0 && (basin_grid[row][column+1] != 0 && basin_grid[row][column+1] != -1)){
                        basin_grid[row][column] = basin_grid[row][column + 1];
                        basin_size[basin_grid[row][column]] ++;
                    }
                }
                if (column > 0){
                    if (basin_grid[row][column] == 0 && (basin_grid[row][column-1] != 0 && basin_grid[row][column-1] != -1)){
                        basin_grid[row][column] = basin_grid[row][column-1];
                        basin_size[basin_grid[row][column]] ++;
                    }
                }
                if (row+1 != basin_grid.size()){
                    if (basin_grid[row][column] == 0 && (basin_grid[row+1][column] != 0 && basin_grid[row+1][column] != -1)){
                        basin_grid[row][column] = basin_grid[row+1][column];
                        basin_size[basin_grid[row][column]] ++;
                    }
                }
                if (row>0){
                    if (basin_grid[row][column] == 0 && (basin_grid[row-1][column] != 0 && basin_grid[row-1][column] != -1)){
                        basin_grid[row][column] = basin_grid[row-1][column];
                        basin_size[basin_grid[row][column]] ++;
                    }
                }
            }
        }

        if (all_filled){
            return basin_size;
        }
    }
}

bool sort_fn(int i,int j) { return (i>j); }

int find_max_basins(std::vector<int> &basin_size){
    // sort and return max 3 basins multiplied.
    std::sort (basin_size.begin(), basin_size.end(), sort_fn);
    int result = basin_size[0] * basin_size[1] * basin_size[2];
    return result;
}

int find_risk_and_set_basins(const std::vector<std::vector<int> >&grid,
                               std::vector<std::vector<int> > &basin_grid,
                               int &num_basins){
    int sum_risk = 0;
    // assumption that size of first row of grid == size of other rows
    for (int row = 0; row < grid.size(); row ++){
        for (int column = 0; column < grid[0].size(); column ++){
            int low_point = find_low_point(column, row, grid);
            sum_risk += low_point;
            //setting up basin grid
            if (low_point != 0){
                basin_grid[row][column] = num_basins;
                num_basins ++;
            }
            else if (grid[row][column] == 9){
                basin_grid[row][column] = -1;
            }
            else{
                basin_grid[row][column] = 0;
            }
        }
    }
    return sum_risk;
}