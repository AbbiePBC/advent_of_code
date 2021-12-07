//
// Created by Abbie Currington on 07/12/2021.
//


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const int vent_size = 999;

class CVector {
    public:
        int x,y;
        CVector(){};
};


void process_input(std::string line, CVector &lhs, CVector &rhs){
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

void find_h_v_vents(int lhs, int rhs, std::vector<std::vector<int> > &vec, int idx, char x_y_flag){
    std::cout << "line: " << lhs << " " << rhs << "\n";
    int larger = rhs;
    int smaller = lhs;
    if (lhs > rhs){
        larger = lhs;
        smaller = rhs;
    }
    if (x_y_flag == 'x'){
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


int find_result(std::vector<std::vector<int> > vec){
    int result = 0;
    for(int i = 0; i < vent_size; i++)
    {
        for(int j = 0; j < vent_size; j++)
        {
            if (vec[i][j] >= 2){
                ++result;
            }
            //std::cout << vec[i][j] << " ";
        }
        //std::cout<< "\n";
    }
    return result;
}

int main () {
    std::string line;
    std::ifstream file("../Dec5_input.txt");
    // create a 2d vector initialised to 0:
    std::vector<std::vector<int> > vec(vent_size , std::vector<int> (vent_size, 0));

    if (file.is_open()) {
        while (getline(file, line)) {
            CVector lhs;
            CVector rhs;
            process_input(line, lhs, rhs);
            std::cout << lhs.x << " " << lhs.y << " " << rhs.x << " "<< rhs.y <<"\n";
            if (lhs.x == rhs.x) {
                find_h_v_vents(rhs.y, lhs.y, vec, lhs.x, 'x');
            }
            else if (lhs.y == rhs.y){
                find_h_v_vents(rhs.x, lhs.x, vec, lhs.y, 'y');
            }

        }
        int result = find_result(vec);
        std::cout<< "Part One: " << result << '\n';

    } else std::cout << "Unable to open file";

    return 0;
}