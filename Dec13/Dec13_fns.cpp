//
// Created by Abbie Currington on 22/12/2021.
//

#include "Dec13_fns.h"

void AllCoords::extract_and_store_input(std::ifstream &file){
    std::string line;
    while (getline (file,line)){
        if (line.size() == 0){
            break;
        }
        std::string delimiter = ",";
        std::string x = line.substr(0, line.find(delimiter));
        std::string y = line.substr(x.size() + delimiter.size() , line.find(delimiter, x.size() + delimiter.size() ));
        int int_x = stoi(x);
        int int_y = stoi(y);
        max_x = (int_x > max_x) ? int_x : max_x;
        max_y = (int_y > max_y) ? int_y : max_y;
        coords.emplace_back(Coord(int_x, int_y));
    }
    std::string ignore_text = "fold along "; // storing sz is faster but less clear

    while (getline (file,line)){
        char axis = line[ignore_text.size()];
        int xaxis = 0;
        int yaxis = 0;
        std::string delimiter = "";
        if ( axis == 'x'){
            xaxis = stoi(line.substr(ignore_text.size() + 2, line.find(delimiter, ignore_text.size() + 2)));
            axes.emplace_back(Coord(xaxis, yaxis));
        }
        else{
            yaxis = stoi(line.substr(ignore_text.size() + 2, line.find(delimiter, ignore_text.size() + 2)));
            axes.emplace_back(Coord(xaxis, yaxis));
        }
    }
}


void AllCoords::create_dots(){
    std::vector<int> row (max_x+1,0);
    for (int i = 0; i < max_y+1; i ++){
        dot_grid.emplace_back(row);
    }
    for (auto &coord : coords){
        dot_grid[coord.y][coord.x] = 1;
    }

}

void AllCoords::do_folds(){
    bool first_fold = true;
    for (auto &fold : axes) {
        fold_once(fold);
        //assume the folds are halfway through the paper.
        if (first_fold){
            count_dots();
            first_fold = false;
        }
    }
}


void AllCoords::count_dots(){
    num_dots = 0;
    for (int i = 0; i < max_y+1; i ++){
        for (int j = 0; j < max_x+1; j ++){
            if (dot_grid[i][j] != 0){
                num_dots ++;
            }
        }
    }
    std::cout<<"Part one: "<<num_dots<<std::endl;
}


std::vector<std::vector<int> > create_resized_vec(const int &row_len, const int &num_rows){
    std::vector<std::vector<int> > cpy_grid;
    std::vector<int> row (row_len,0);
    for (int i = 0; i < num_rows; i ++){
        cpy_grid.emplace_back(row);
    }
    return cpy_grid;
}


// x and y fns doing v similar things but seemed too contrived to combine?
void AllCoords::update_grid_y(const int &resize_y, std::vector<std::vector<int> > &cpy_grid){
    for (int i = 0; i < resize_y; i++) {
        for (int j = 0; j < max_x + 1; j++) {
            cpy_grid[i][j] = dot_grid[i][j] + dot_grid[max_y - i][j];
        }
    }
    dot_grid = cpy_grid;
    max_y = resize_y - 1; // to keep +1 consistent
}


void AllCoords::update_grid_x(const int &resize_x, std::vector<std::vector<int> > &cpy_grid){
    for (int i = 0; i < max_y+1; i++) {
        for (int j = 0; j < resize_x; j++) {
            cpy_grid[i][j] = dot_grid[i][j] + dot_grid[i][max_x - j];
        }
    }
    max_x = resize_x - 1;
    dot_grid = cpy_grid;
}



void AllCoords::fold_once(Coord &fold){
    // todo resizing vector would implictly copy so no better
    // todo could just use updating subsections of original vector but not really worth it
    if (fold.x == 0){
        std::vector<std::vector<int> > cpy_grid = create_resized_vec(max_x+1, fold.y);
        update_grid_y(fold.y, cpy_grid);
    }
    else {
        std::vector<std::vector<int> > cpy_grid = create_resized_vec(fold.x, max_y+1);
        update_grid_x(fold.x, cpy_grid);
    }
}


void AllCoords::print_output(){
    std::cout<<"Part two:\n";
    for (int i = 0; i < max_y+1; i ++){
        for (int j = 0; j < max_x+1; j ++){
            if (dot_grid[i][j] != 0){
                std::cout<<"\033[1;31m1 ";
            }
            else{
                std::cout<<"\033[0m0 ";
            }
        }
        std::cout<<"\n";
    }
}
