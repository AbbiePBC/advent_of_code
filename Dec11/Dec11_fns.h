//
// Created by Abbie Currington on 15/12/2021.
//

#ifndef ADVENTOFCODE_DEC11_FNS_H
#define ADVENTOFCODE_DEC11_FNS_H


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const int row_size = 10;
//const int num_steps = 100;
enum state {sync, done_flash};

class Octopods{
public:
    std::vector<std::vector<int> > grid;
    static std::vector<std::vector<int> > extract_and_store_input(std::ifstream &ifstream);
    int num_flashes;
    int state = -1;
    void increment_energy();
    void do_flashes();
    bool flash(const int &row, const int &element);
    void print_1() const{std::cout<<"part 1: "<<num_flashes<<std::endl;};
    void print_2() const{std::cout<<"part 2: "<<state<<std::endl;};

    int step = 0;
    Octopods(std::ifstream &file, const int &num_steps){
        num_flashes = 0;
        grid = extract_and_store_input(file);
        while (true){
            increment_energy(); // doesn't seem to be any point to return grid, but apparently it's bad not to return stuff?
            do_flashes();
            if (step + 1 == num_steps){
                print_1();
            }
            if (state == sync){
                state = step + 1;
                print_2();
                break;
                // assumption that synchronisation occurs after the number of initial steps.
            }

            step ++;
        }
    }
};



#endif //ADVENTOFCODE_DEC11_FNS_H
