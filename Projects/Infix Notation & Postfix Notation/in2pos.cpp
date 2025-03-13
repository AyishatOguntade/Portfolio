//https://en.cppreference.com/w/cpp/container/stack
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <stack>

// test to see if it is a digit 
bool isNumber(const std::string& str) {
    // If the string is empty, it is not a number
    if (str.empty()) {
        return false;
    }

    // Set the starting index for checking digits
    int start = 0;

    if (str[0] == '-') {
        // Set start to 1 to skip the minus sign
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

//  is operator 
bool isOpp(std::string c){
    if( c == "+" || c == "-" || c == "/" || c == "*" || c == "^"){
        return true;
    }
    else{
        return false;
    }
}
// PEMDAS 
int prec(std::string c){
    if(c == "^"){
        return 3;
    }
    else if(c == "*" || c == "/"){
        return 2;
    }
    else if(c == "+" || c == "-"){
        return 1;
    }
    else{
        return -1;
    }
}

std::string in2pos(std::stack<std::string>& s, std::vector<std::string>& infix){
    std::string postfix;

    for(int i=0; i < infix.size(); i++){
        if(isNumber(infix[i])){
            postfix += infix[i] + " ";
        }
        else if(infix[i] == "("){
            s.push(infix[i]);
        }
        else if(infix[i] == ")"){
            while(s.top() != "(" && !s.empty()){
                std::string temp = s.top();
                postfix += temp + " ";
                s.pop();
            }
            if(s.top() == "("){
                s.pop();
            }
        }
        else if(isOpp(infix[i])){
            if(s.empty()){
                s.push(infix[i]);
            }
            else{
                if(prec(infix[i]) > prec(s.top())){
                    s.push(infix[i]);
                }
                else if(prec(infix[i])== prec(s.top()) && infix[i] =="^"){
                    s.push(infix[i]);
                }
                else{
                    while(!s.empty() && prec(s.top()) >= prec(infix[i])){
                        std::string temp = s.top();
                        postfix += temp + " ";
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }

    while(!s.empty()){
        postfix += s.top() + " ";
        s.pop();
    }

    return postfix;
}

int main(int argc, char *argv[]){

    std::string line = argv[1];
    std::vector<std::string> el; 
    std::istringstream ss(line);
    std::string temp;

    std::stack<std::string> stack;
    std::string output;
    //Create a vector with the elements 
    while(ss >> temp){
        el.push_back(temp);
    }
    // call main function 
    output = in2pos(stack , el);

    std:: cout << output << std::endl;
    /*
    for(std::string j : el){
        std::cout<< j << " ";
    }
    std:: cout << std::endl;
    */
    return 0;
}
