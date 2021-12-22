//
// Created by Abbie Currington on 21/12/2021.
//


#include "Dec11_fns.h"

std::vector<std::vector<int> > Octopods::extract_and_store_input(std::ifstream &file){

    std::vector<std::vector<int> > oct_grid;
    oct_grid.reserve(row_size);
    std::string line;
    while (getline (file,line) ){
        std::vector<int> row;
        row.reserve(row_size);
        for (int i = 0; i < line.size(); i ++){
            row.emplace_back(line[i] - '0');
        }
        oct_grid.emplace_back(row);
    }
    return oct_grid;
}


void Octopods::increment_energy(){
    for (int row = 0; row < grid.size(); row++){
        for (int element = 0; element < grid.size(); element ++){
            grid[row][element] ++;
        }
    }
}

void update_line(std::vector<int> &row, const int &element){
    int min = (element -1 > 0) ? element-1 : 0;
    int max = (element +1 < row.size()-1 ) ? element +1 : row.size()-1;
    for (int i = min; i < max+1; i ++){
        if (row[i] != 0){
            row[i] ++;
        }
    }
}


bool Octopods::flash(const int &row, const int &element){
    // will be repetitive/pass around more args even if this is tidied, so not much point
    if (row == 0){
        // don't change top row
        update_line(grid[row], element);
        update_line(grid[row+1], element);
    }
    else if (row == grid.size() - 1){
        // don't change bottom row
        update_line(grid[row-1], element);
        update_line(grid[row], element);
    }
    else{
        update_line(grid[row-1], element);
        update_line(grid[row], element);
        update_line(grid[row+1], element);
    }
    grid[row][element] = 0;
    num_flashes ++;
    return true;
}


void Octopods::do_flashes(){
    bool found_9 = true;
    bool synchronised = true;
    while (found_9){
        found_9 = false;
        synchronised = true;
        for (int row = 0; row < grid.size(); row++){
            for (int element = 0; element < grid.size(); element ++){
                if (grid[row][element] > 9){
                    found_9 = flash(row, element);
                }
                else if (grid[row][element] != 0){
                    synchronised = false;
                }
            }
        }
        if (synchronised){
            // if synchronised, all zero, so !found_9 would also break
            state = sync;
            break;
        }
        else if (!found_9){
            break;
        }
    }
}