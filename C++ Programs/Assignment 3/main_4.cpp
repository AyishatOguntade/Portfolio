#include <iostream>
#include <vector>
#include <string>
// might be a weird input 
// ask to see if the way its getting the numbers is correct 
int main() {
    std::vector<int> sequence;
    int input;

    //Read integers until the user enters 0
    while (std::cin >> input) {
        //std:: cout <<input << std::endl;
        if (sequence.size() > 100) {
            break;
        }
        else{
        sequence.push_back(input);
        //std:: cout << input;
        }
    }
    //std:: string line;
   // std:: getline(std:: cin, line);
    //std:: cout << line;

      // Check if the sequence is sorted in non-increasing order
      // issure with if statement might be going out of range 
    bool sorted = true;
    for (int i = 1; i < sequence.size(); i++) {
            //std:: cout << sequence[i+1];
        if (sequence[i] > sequence[i -1]){
            //std:: cout << line[i];
            sorted = false;
            break;
        }
    }

    if (sorted) {
        std::cout << "Sorted" << std::endl;
    } else {
        std::cout << "Not Sorted" << std::endl;
    }

    return 0;



    return 0;
}