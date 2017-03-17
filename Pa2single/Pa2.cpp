#include <iostream>
#include "Pa2.h"
#include <string>
#include <typeinfo>

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
    
    LinkedList * memory = new LinkedList();
    
    for(int i = 0; i < 32; i++) {
        memory->insert(i, i + 1, "");
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
                std::string name;
                int size = 0;
                int pages;
                std::cout << "Program name - ";
                //TODO CLEAR BUFFER
                std::cin.clear();
                std::cin.ignore(256, '\n');
                std::getline (std::cin,name);
                
                std::cout << "Program size (KB) - ";
                std::cin.clear();
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
                
                if (memory->isRunning(name)){
                    std::cout<<"Error, Program "<<name<<" is already running."<<std::endl;
                } else {

                    if(memory->addProgram(name, pages, isBestFit)){
                        std::cout<<"Program "<<name<<" added successfully, "<<pages<<" pages used"<<std::endl;
                    }   else    {
                        std::cout<<"Error, Not enough memory for program"<<name<<std::endl;
                    }
                }
                
                break;
        }
    } while(validateChoice != 5);
    
    return 0;
}