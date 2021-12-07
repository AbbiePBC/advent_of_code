//
// Created by Abbie Currington on 02/12/2021.
//

//

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

const int num_directions =  3;
enum Dirs {forward, down, up};

class Direction{
    public:
        std::string dir;
        int sub_tot;
        explicit Direction(std::string input){
            dir = input;
            sub_tot = 0;
        }
        int idx () const {return (dir.size() + 1);};
};

class PartTwo{
    public:
        int aim, depth, horizontal;
        PartTwo(int a, int d, int h){
            aim = a;
            depth = d;
            horizontal = h;
        };

};

// look at vectors
// std::vector<Direction> obj;
// https://en.cppreference.com/w/cpp/container/vector


int part_one(std::string line, Direction &dir){
    int val = atoi(&line[dir.idx()]);
    dir.sub_tot += val;
    return val;
}


void part_two(int val, PartTwo *movement_subtotals, int i){
    switch(i){
        case forward:
            movement_subtotals->depth += val * movement_subtotals->aim;
            movement_subtotals->horizontal += val;
            break;
        case down:
            movement_subtotals->aim += val;
            break;
        case up:
            movement_subtotals->aim -= val;
            break;
    }
}


int main () {
    std::string line;
    std::ifstream file ("../Dec2_input.txt");

    Direction movement_in_direction[num_directions] = {Direction("forward"),
                                                       Direction("down"), Direction("up")};
    PartTwo movement_subtotals = PartTwo(0,0,0);

    int val = 0;

    if (file.is_open())
    {
        while ( getline (file,line) )
        {
            for (int i = 0; i < num_directions; i ++)
            {
                if(line.find(movement_in_direction[i].dir) != std::string::npos){
                    val = part_one(line, movement_in_direction[i]);
                    part_two(val, &movement_subtotals, i);
                }
            }
        }
        file.close();
        // assume bracket here is > 0
        int result = movement_in_direction[forward].sub_tot * (
                movement_in_direction[down].sub_tot - movement_in_direction[up].sub_tot);
        std::cout << "Part One result: " << result << '\n';
        result = movement_subtotals.horizontal * movement_subtotals.depth;
        std::cout << "Part Two result: " << result << '\n';
    }
    else std::cout << "Unable to open file";

    return 0;
}