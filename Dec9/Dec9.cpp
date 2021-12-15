//
// Created by Abbie Currington on 15/12/2021.
//

#include "Dec9_fns.h"


int main () {
    std::ifstream file ("../../Dec9/Dec9_input.txt");

    if (file.is_open())
    {
        int num_basins = 1; // not zero indexing this, as 0 can initialise
        std::vector<std::vector<int> > grid = extract_and_store_input(file);
        file.close();

        std::vector<std::vector<int> > basin_grid = grid;
        int sum_risk = find_risk_and_set_basins(grid, basin_grid, num_basins);
        std::vector<int> basin_size = fill_basins(basin_grid, num_basins);
        int part_two_result = find_max_basins(basin_size);
        std::cout<<"part 1 result: "<<sum_risk<<std::endl;
        std::cout<<"part 2 result: "<<part_two_result<<std::endl;
    }
    else std::cout << "Unable to open file";

    return 0;
}
