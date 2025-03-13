#include <iostream>
#include <string>
#include <sstream>
#include <vector>
//d
int main (){
    
    std::string input;
    std::getline(std::cin, input);
    std::stringstream ss(input);

    std::vector<int> numbers;
    int num;
    while (ss >> num) {
        numbers.push_back(num);
    }

    int firstNum = numbers[0];
    int count = 0;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == firstNum) {
            count= count +1;
        }
    }

    std::cout << count << std::endl;

    return 0;
}