#include <iostream>
#include "pa2.h"
#include <string>
#include <typeinfo>

class Node {
    public:
        Node(bool t, string n);
        void insert(bool t, string n);
        void setName(string n);
        void setTaken(bool t);
    private:
        bool taken;
        string name;
        Node * next; 
};

Node::Node(bool t, string n){
    taken = t;
    name = n;
    next = NULL;
};

void Node::insert(bool t, string n){
    if(next == NULL || next == 0){
        next = new Node(t, n);
    } else {
        next->insert(t, n);
    }
};

//Change the name of the node. The name is the name of the program taking up it's memory
void Node::setName(string n) {
    name = n;
};  

//Change whether the node (of memory) is being used or not
void Node::setTaken(bool t) {
    taken = t;
};

class LinkedList {
    private:
        Node * head;
    public:
        LinkedList();
        void insert(bool t, string n);
};

LinkedList::LinkedList(){
    head = NULL;
}

void LinkedList::insert(bool t, string n) {
    
    if(head == NULL || head == 0){
        head = new Node(t, n);
    } else {
        head->insert(t, n);
    }
};

class space {
    public:
        int size;
        Node * start;
};

int main(int argc, char ** argv){
    
    bool isBestFit;
    
    if (argc < 2){
        std::cout << "Not enough arguments."<<std::endl;
        return 1;
    } else if (argc > 2) {
        std::cout << "Too many arguments."<<std::endl;
        return 1;
    }
    std::string best = "best";
    std::string worst = "worst";
    
    if (best.compare(argv[1]) == 0){
        std::cout << "best"<<std::endl;
        isBestFit = true;
    } else if (worst.compare(argv[1]) == 0) {
        std::cout << "Worst"<<std::endl;
        isBestFit = false;
    } else {
        std::cout << "Incorrect arguments. Please use 'best' or 'worst'"<<std::endl;
        return 1;
    }
    
    LinkedList * memory; // = new LinkedList();
    
    for(int i = 0; i < 32; i++) {
        memory->insert(false, "");
    }
    
    int validateChoice;
    do{
        std::cout << "\t1. Add program\n\t2. Kill program\n\t3. Fragmentation\n\t4. Print memory\n\t5. Exit" << std::endl;
        
        bool end = false;
        while(!end) {
            std::cout << "choice - ";
            std::cin >> validateChoice;
            //Checking if input is an int
            while (std::cin.fail()) { //If the input value from the stream was not an int
                std::cin.clear();
                std::cin.ignore(256, '\n');
                std::cout << "Input is not a number. Please try again: \nchoice - " << std::endl;
                
                std::cin >> validateChoice;
            }
            
            if (validateChoice > 5 || validateChoice < 1) {
                std::cout << "Choice must be within 5 and 1, inclusive."<<std::endl;
            } else {
                end = true;
            }
        }
        
        switch(validateChoice) {
            case 1:
                string name;
                int size;
                int pages;
                std::cout << "Program name - ";
                //TODO CLEAR BUFFER
                std::cin.clear();
                std::cin.ignore(256, '\n');
                std::getline (std::cin,name);
                
                std::cout << "Program size (KB) - ";
                
                std::cin >> size;
                
                while(std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(256, '\n');
                    std::cout << "Input must be an integer. Please try again.\nProgram size (KB) - ";
                    std::cin >> size;
                    std::cout << std::endl;
                }
                
                if(size % 4 == 0) {
                    pages = size/4;
                } else {
                    pages = size/4 + 1;
                }
                
                std::cout<<pages<<std::endl;
                
                break;
        }
    } while(validateChoice != 5);
    
    return 0;
}



