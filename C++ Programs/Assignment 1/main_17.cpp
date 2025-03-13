#include <iostream>
#include <iomanip>

int main(){

std::string letter;
std:: cin >> letter;

if(letter == "A" || letter == "a"){
    std::cout << "Excellent";
}
else if (letter =="B"|| letter =="b"){
    std:: cout <<"Good";
}
else if(letter == "C" || letter =="c"){
    std:: cout << "Average";
}
else if(letter == "D"|| letter == "d"){
    std:: cout << "Poor";
}
else{
    std:: cout << "Failing";
}


    return 0;
}