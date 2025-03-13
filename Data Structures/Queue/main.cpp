#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "queue.h"

int main(int argc, char* argv[]) {
    std::string fname = argv[1];
    std::ifstream readFile(fname);  
    Queue *q1;

    std::string tempstr; 
    std::getline(readFile, tempstr);
    std::istringstream ss(tempstr); 
    std::vector<int> tempvec;

    int num;
    while (ss >> num){
        tempvec.push_back(num);
    }

    if (tempvec.size() == 0){
        q1 = new Queue();  
    } 
    else if(tempvec.size() ==1){
        q1 = new Queue(tempvec[0]);
    }
    else{
        q1 = new Queue(tempvec);
    }
    //call print fucntion
    std::cout << q1->to_string() << std::endl;
    //nque add to the end 
    //dque remove to the front
    //std::string tempstr2; 
    while (std::getline(readFile, tempstr)) {
        if (tempstr.size() != 0) { 
            if (tempstr == "-") {  // Dequeue command
                q1->dequeue();
                std::cout << q1->to_string() << std::endl;
            } else if (tempstr == "?") {  // Peek command
                int peekValue = q1->peek();  // Get value from peek
                std::cout << peekValue << std::endl;  // Print only the peek value
                continue;  // Skip printing the queue after peek
            } else { 
                int data = std::stoi(tempstr);  // Convert to integer
                q1->enqueue(data);
                std::cout << q1->to_string() << std::endl;  // 
            }
        }
    }

        // // Print the queue state after each command except peek
        // if (tempstr[0] != '?') {
        //     std::cout << q1->to_string() << std::endl;
        // }
    
    
    readFile.close();
    delete q1;
    return 0; 
}
