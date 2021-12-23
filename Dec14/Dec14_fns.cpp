//
// Created by Abbie Currington on 23/12/2021.
//

#include "Dec14_fns.h"

enum pos{e1=0, e2=1, e3=6};


std::shared_ptr<Element> Polymer::extract_and_store_input(std::ifstream &file){
    std::string line;
    // read first line and store element by element in polymer
    std::shared_ptr<Element> head = std::make_shared<Element>('Z');
    while (getline (file,line)) {
        if (line.size() == 0){
            break;
        }
        for (char & letter : line){
            auto tmp = std::make_shared<Element>(letter);
            tmp->next = head;
            head = tmp;
        }
    }

    // read steps
    while (getline (file,line)) {
        steps.emplace_back(line[e1], line[e2], line[e3]);
    }
    return head;
}

void Polymer::prepare_insertion(std::shared_ptr<Element> &head){

    auto trav= head;
    for (auto &step: steps) {
        while (trav->next != nullptr) {
            // polymer created back to front; check elements in opposite order
            std::cout << step.element2 << step.element1 << step.insert << std::endl;
            if (trav->el == step.element2 && trav->next->el == step.element1) {
                trav->to_add = step.insert;
                std::cout<<"adding"<<trav->to_add<<std::endl;
            }
            trav=trav->next;
        }
        trav = head;
    }

//        auto tmp = head;
//        while (tmp->el != 'Z'){
//            std::cout<<tmp->el<<std::endl;
//            tmp=tmp->next;
//        }
//        exit(1);

}

std::shared_ptr<Element> add_element(std::shared_ptr<Element> &head_cpy){
    auto tmp = head_cpy->next;
    head_cpy->next = std::make_shared<Element>(head_cpy->to_add);
    head_cpy->next = tmp;
    return tmp;
}


void Polymer::insert_elements(std::shared_ptr<Element> &head) {

    auto trav = head;
    auto tmp= head;


    while ((trav)->next != nullptr) {
        std::cout<<(trav)->el<<std::endl;
        if ((trav)->to_add != 'Z'){
            std::cout<<"adding"<<(trav)->to_add<<std::endl;
            (trav)=add_element(trav);
            (trav)=(trav)->next; // progress forward twice
        }
        (trav)=(trav)->next;
    }

//    while (tmp->el != 'Z'){
//        std::cout<<tmp->el<<std::endl;
//        tmp=tmp->next;
//    }


}

