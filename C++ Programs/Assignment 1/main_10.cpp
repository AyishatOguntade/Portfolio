#include <iostream>
#include <iomanip>

int main(){

int num;

std:: cin >> num;

switch (num) {
case 0:
    std:: cout << "Zero";
    break;
case 1:
    std:: cout << "One";
    break;
case 2:
    std:: cout<< "Two";
    break;
case 3:
    std:: cout << "Three";
    break;
case 4:
    std::cout << "Four";
    break;
case 5:
    std:: cout << "Five";
    break;
case 6: 
    std:: cout << "Six";
    break;
case 7:
    std:: cout << "Seven";
    break;
case 8:
    std:: cout << "Eight";
    break; 
case 9:
    std:: cout << "Nine";
    break;  
default:
    std::cout<< "Not a valid number";
}




    return 0;
}