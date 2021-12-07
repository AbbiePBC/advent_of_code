//
// Created by Abbie Currington on 06/12/2021.
//

// delete bingo cards from the vector as soon as they win, until there is 1 left
// assume that all cards will win eventually (i.e. don't need to have a lag before deletion in case no others win)
// keep track of the last input value to cause winning.

#include <iostream>
#include <fstream>
#include <vector>

const int array_size = 5;

void read_inputs(std::string line, std::vector<int> &inputs){
    int idx = 0;
    int val = 0;
    // this is inefficient
    while (1) {
        if (line[idx] == ' ' && (line[idx + 1] == ' ' || idx == 0)){
            // double spaces for single character numbers shouldn't cause 'val' = 0 to be added.
            idx++;
            continue;
        }
        if (line[idx] == ',' || line[idx] == '\0' || line[idx] == ' '){
            inputs.push_back(val);
            val = 0;
        }
        else {
            val = val * 10 + (line[idx] - '0');
        }
        if(line[idx] == '\0' || line[idx] == '\n'){
            return;
        }
        idx++;
    }
}


void create_bingo_cards(const std::string& line, std::vector<int> &card_line, std::vector<std::vector<int > > &bingo_card,
                        std::vector<std::vector<std::vector <int> > > &all_cards) {

    read_inputs(line, card_line);
    bingo_card.push_back(card_line);
    card_line.clear();

    if (bingo_card.size() == array_size) {
        all_cards.push_back(bingo_card);
        bingo_card.clear();
    }
}


void compare_inputs(int input, std::vector<std::vector<std::vector <int> > > &all_cards){
    // this is v v inefficient :(
    for (auto & all_card : all_cards){
        for (int i = 0; i < array_size; i ++){
            for (int y = 0; y < array_size; y ++){
                if (input == all_card[i][y]){
                    all_card[i][y] = -1;
                }
            }
        }
    }
}


int check_bingo(std::vector<std::vector<std::vector <int> > > &all_cards){

    for (int i = all_cards.size() - 1; i > -1 ; i --){
        for (int j = 0; j < array_size; j ++){
            if ((all_cards[i][j][0] == -1 && all_cards[i][j][1] == -1 && all_cards[i][j][2] == -1 &&
                all_cards[i][j][3] == -1 && all_cards[i][j][4] == -1) || (
                all_cards[i][0][j] == -1 && all_cards[i][1][j] == -1 && all_cards[i][2][j] == -1 &&
                all_cards[i][3][j] == -1 && all_cards[i][4][j] == -1))
            {
                if (all_cards.size() == 1){
                    return 1; //deliberately success val
                }
                all_cards.erase(all_cards.begin() + i);
            }
        }
    }
    return 0;
}


int do_multiplication(int input, std::vector<std::vector<int > > bingo_card){
    int tot = 0;
    for (int i = 0; i < array_size; i ++){
        for (int j = 0; j < array_size; j ++){
            if (bingo_card[i][j] != -1){
                tot += bingo_card[i][j];
            }
        }
    }
    return tot*input;
}


int main () {
    std::string line;
    std::ifstream file("../Dec4_input.txt");

    bool first_line = true;
    std::vector<int> inputs;
    std::vector<int> card_line;
    std::vector<std::vector<int > > bingo_card;
    std::vector<std::vector<std::vector <int> > > all_cards;

    if (file.is_open()) {
        while (getline(file, line)) {
            if (first_line) {
                read_inputs(line, inputs);
                first_line = false;
            }
            else if (line != "\0") {
                create_bingo_cards(line, card_line, bingo_card, all_cards);
            }
        }

        file.close();

        // compare inputs
        int current_input = 0;

        for (int input : inputs) {
            current_input = input;
        }
        for (int i = 0; i < inputs.size(); i++){
            current_input = inputs[i];
            compare_inputs(current_input, all_cards);
            int retval = 0;
            if (i >= array_size){ //can't have a full row/column otherwise (assume no duplicates)
                retval = check_bingo(all_cards);
            }
            if (retval == 1){
                break;
            }

        }
        int result = do_multiplication(current_input, all_cards[0]);
        std::cout << "\nPart Two result: " << result << '\n';

    } else std::cout << "Unable to open file";

    return 0;
}