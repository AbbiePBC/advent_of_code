//
// Created by Abbie Currington on 22/12/2021.
//

#ifndef ADVENTOFCODE_DEC13_FNS_H
#define ADVENTOFCODE_DEC13_FNS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


class Coord{
public:
    int x;
    int y;
    Coord(int &x_in, int &y_in){
        x = x_in;
        y = y_in;
    }
};


class AllCoords{
public:
    std::vector<Coord> coords;
    int max_x;
    int max_y = 0;
    int num_dots;
    void extract_and_store_input(std::ifstream &file);
    std::vector<Coord> axes;
    std::vector<std::vector<int > > dot_grid;
    void create_dots();
    void do_folds();
    void fold_once(Coord &fold);
    void update_grid_y(const int &resize_y, std::vector<std::vector<int> > &cpy_grid);
    void update_grid_x(const int &resize_x, std::vector<std::vector<int> > &cpy_grid);
    void count_dots();
    void print_output();
    AllCoords(std::ifstream &file){
        extract_and_store_input(file);
        create_dots();
        do_folds();
        print_output();
    }
};




#endif //ADVENTOFCODE_DEC13_FNS_H
