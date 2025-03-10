#include "linked_list.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

int main(int argc, char* argv[]) {
    std::string fname = argv[1];
    std::ifstream readFile(fname); 


    std::string tempstr; 
    std::getline(readFile, tempstr);
    std::istringstream ss(tempstr); 
    std::vector<int> tempvec;

    int num;
    while (ss >> num){
        tempvec.push_back(num);
    }

    // Declare List here so it's available throughout the function
    LinkedList* List1;

    if (tempvec.size() == 0){
        List1 = new LinkedList(); 
    } 
    else if (tempvec.size() == 1){
        List1 = new LinkedList(tempvec[0]); 
    } 
    else{
        List1 = new LinkedList(tempvec);
    }

    std::cout << List1->to_string() << std::endl;

    std::string tempstr2; 
    while (std::getline(readFile, tempstr2)){
        std::istringstream ss2(tempstr2); 
        int num2;

        if (ss2 >> num){ 
            if (ss2 >> num2){
                List1->insert(num, num2); 
                std::cout << List1->to_string() << std::endl; 
            } 
            else{
                if (tempstr2.find('?') != std::string::npos){
                    std::cout << List1->contains(num) << std::endl;
                } 
                else if (num < 0){
                    num *= -1;
                    List1->remove(num);
                    std::cout << List1->to_string() << std::endl;
                } 
                else if (num % 2 == 1){
                    List1->push_front(num); 
                    std::cout << List1->to_string() << std::endl;
                }
                else if (num % 2 == 0){
                    List1->push_back(num);
                    std::cout << List1->to_string() << std::endl; 
                }
            }
        }
    }
    return 0; 
}

