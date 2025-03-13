#include<iostream>
#include<vector>
#include<stack>
#include<math.h>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include<iomanip>


//fixed
bool isNumber(const std::string& str) {
    // If the string is empty, it is not a number
    if (str.empty()) {
        return false;
    }

    // Set the starting index for checking digits
    int start = 0;

    if (str[0] == '-') {
        start = 1;
        
        // If the string only contains the minus sign, it is not a number
        if (str.size() == 1) {
            return false;
        }
    }

    // Check each character from the starting index to the end of the string
    for (int i = start; i < str.size(); ++i) {
        // If any character is not a digit, the string is not a number
        if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

bool isOpp(std::string c){
    if( c == "+" || c == "-" || c == "/" || c == "*" || c == "^"){
        return true;
    }
    else{
        return false;
    }
}

float eval(std::stack<float>& s, std::vector<std::string>& el) {
    for(int i = 0; i < el.size(); i++) {
        if(isNumber(el[i])) {
            s.push(std::stof(el[i]));
        }
        else if(isOpp(el[i])) {
            float val1 = s.top();
            s.pop();
            float val2 = s.top();
            s.pop();
            
            if(el[i] == "+") {
                s.push(val2 + val1);
            }
            else if(el[i] == "-") {
                s.push(val2 - val1);
            }
            else if(el[i] == "/") {
                s.push(std::floor(val2 / val1));
            }
            else if(el[i] == "*") {
                s.push(val2 * val1);
            }
            else if(el[i] == "^") {
                s.push(std::pow(val2, val1));
            }
        }
    }
    
    return s.top();
}



int main(int argc, char *argv[]){

    std::string line = argv[1];
    std::vector<std::string> el; 
    std::istringstream ss(line);
    std::string temp;

    std::stack<float> stack;
    float ans;
    //Create a vector with the elements 
    while(ss >> temp){
        el.push_back(temp);
    }
    // call main function 

    ans = eval(stack,el);
    //if ans isnt a whole number add 1 to the answer?? 
    int myInt = static_cast<int>(ans); 

    std:: cout << myInt << std::endl;
    /*
    for(std::string j : el){
        std::cout<< j << " ";
    }
    std:: cout << std::endl;
    */
    return 0;
}
