#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "priority_queue.h"

int main (int argc, char* argv[]){
    std::string fname = argv[1];
    std::ifstream readFile(fname);  
    PriorityQ *q1;

    std::string tempstr; 
    std::getline(readFile, tempstr);
    std::istringstream ss(tempstr); 
    std::vector<int> tempvec;

    int num;
    while (ss >> num){
        tempvec.push_back(num);
    }

    if (tempvec.size() == 0){
        q1 = new PriorityQ();  
    } 
    else if(tempvec.size() == 1){
        q1 = new PriorityQ(tempvec[0],0);
    }
    else{
        q1 = new PriorityQ(tempvec);
    }
    //call print fucntion
    std::cout << q1->to_string() << std::endl; 
    // read in the rest of the file 
    while (getline(readFile, tempstr)){
        if(tempstr.length()!=0){
            if(tempstr == "?"){
                q1->peek();
            }
            else if(tempstr == "-"){ 
                // std::cout<< q1->to_string()<<"dequeue"<< std::endl;
                q1->dequeue();
                std::cout<< q1->to_string()<< std::endl;
            } else{
                std::string num1;
                std::string num2;
                std::stringstream ss(tempstr);
                ss>> num1 >> num2;
                q1->enqueue(std::stoi(num1),std::stoi(num2));
                std::cout<< q1->to_string()<< std::endl;
            }
        }
    }
}
