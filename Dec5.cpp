//
// Created by Abbie Currington on 07/12/2021.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const int vent_size = 999;
enum direction_flag{X,Y};

struct CVector {
    int x,y;
};

// possible alternatives:
// std::tuple<CVector, CVector> process_input(std::string line);
// std::pair<CVector, CVector> process_input(std::string line);
void parse_coordinate_pairs(std::string line, CVector &lhs, CVector &rhs){
    // don't erase, but update idx.
    std::string delimiter = ",";
    lhs.x = stoi(line.substr(0, line.find(delimiter)));
    line.erase(0, line.find(delimiter) + delimiter.length());
    delimiter = " -> ";
    lhs.y = stoi(line.substr(0, line.find(delimiter)));
    line.erase(0, line.find(delimiter) + delimiter.length());
    delimiter = ",";
    rhs.x = stoi(line.substr(0, line.find(delimiter)));
    line.erase(0, line.find(delimiter) + delimiter.length());
    rhs.y = stoi(line);

}

void find_h_v_vents(int lhs, int rhs, std::vector<std::vector<int> > &vec, int idx, int x_y_flag){
    int larger = rhs;
    int smaller = lhs;
    if (lhs > rhs){
        larger = lhs;
        smaller = rhs;
    }
    if (x_y_flag == X){ // explicit
        // larger + 1 so that largest idx == larger
        for (int i = smaller; i < larger + 1; i ++){
            vec[i][idx] ++;
        }
    }
    else{
        for (int i = smaller; i < larger + 1; i ++){
            vec[idx][i] ++;
        }
    }
}


void find_diagonals(CVector lhs, CVector rhs, std::vector<std::vector<int> > &vec){
    CVector start;
    CVector end;

    if (lhs.x > rhs.x && lhs.y > rhs.y){
        start=rhs;
        end=lhs;
    }
    else if (rhs.x > lhs.x && rhs.y > lhs.y){
        start=lhs;
        end=rhs;
    }
    if ((lhs.y > rhs.y && lhs.x > rhs.x) || (lhs.x < rhs.x && lhs.y < rhs.y)){
        //std::cout << "diagonal down" << start.x << start.y<< "\n";
        for (int i = start.x; i < end.x + 1; i ++){
            vec[start.y][i] ++;
            //std::cout << "updated at " << i << start.y << '\n';
            start.y ++;  // one to one increasing w x
        }
        return;
    }
    if (lhs.x > rhs.x && lhs.y < rhs.y){
        start=rhs;
        end=lhs;
    }
    else if (lhs.y > rhs.y && lhs.x < rhs.x){
        start=lhs;
        end=rhs;
    }
    //std::cout << "diagonal down"<< start.x << end.y<<"\n";
    for (int i = start.x; i < end.x + 1; i ++){
        //std::cout << "updated at " << i << start.y << '\n';
        vec[start.y][i]++;
        start.y --;  // one to one decreasing w x
    }

    // larger + 1 so that largest idx == larger

}


int count_common_vents(const std::vector<std::vector<int> > &vec){
    int result = 0;
    for(int i = 0; i < vent_size; i++)
    {
        for(int j = 0; j < vent_size; j++)
        {
            if (vec[i][j] >= 2){
                ++result;
            }
            std::cout << vec[i][j] << " ";
        }
        std::cout<< "\n";
    }
    return result;
}

int main () {
    std::string line;
    std::ifstream file("../Dec5_input.txt");
    // create a 2d vector initialised to 0:
    std::vector<std::vector<int> > vec(vent_size , std::vector<int> (vent_size, 0));

    #define PART_TWO 1

    if (file.is_open()) {
        while (getline(file, line)) {
            CVector lhs;
            CVector rhs;
            parse_coordinate_pairs(line, lhs, rhs);
            if (lhs.x == rhs.x) {
                find_h_v_vents(rhs.y, lhs.y, vec, lhs.x, X);
            }
            else if (lhs.y == rhs.y){
                find_h_v_vents(rhs.x, lhs.x, vec, lhs.y, Y);
            }
            else if (abs(lhs.x - rhs.x) == abs(lhs.y - rhs.y) && PART_TWO){
                // easier to write new fn for now than generalise above fn.
                find_diagonals(lhs, rhs, vec);
            }

        }
        int result = count_common_vents(vec);
        std::string str = (PART_TWO) ? "Part Two: " : "Part One: ";
        std::cout<< str << result << '\n';

    } else std::cout << "Unable to open file";

    #undef PART_TWO

    return 0;
}