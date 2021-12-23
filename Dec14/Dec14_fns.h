//
// Created by Abbie Currington on 23/12/2021.
//

#ifndef ADVENTOFCODE_DEC14_FNS_H
#define ADVENTOFCODE_DEC14_FNS_H


#include <iostream>
#include <fstream>
#include <string>
#include <vector>


class Element{
public:
    char el = 'Z';
    std::shared_ptr<Element> next;
    char to_add = 'Z';
    Element(char input){
        el = input;
        next = nullptr;
    }
};

class Steps{
public:
    char element1;
    char element2;
    char insert;
    Steps(char e1, char e2, char in){
        element1 = e1;
        element2 = e2;
        insert = in;
    }
};

class Polymer{
public:
    std::vector<Steps> steps;
    std::shared_ptr<Element> extract_and_store_input(std::ifstream &file);
    void prepare_insertion(std::shared_ptr<Element> &head);
    void insert_elements(std::shared_ptr<Element> &head);
    Polymer(std::ifstream &file){
        std::shared_ptr<Element> head = extract_and_store_input(file);
        prepare_insertion(head);
        insert_elements(head);

    }
};
#endif //ADVENTOFCODE_DEC14_FNS_H
