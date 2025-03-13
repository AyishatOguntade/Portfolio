#include <iostream>
#include <iomanip>

int main(){
    std:: cout << std:: fixed << std:: setprecision (4);
    double num1;
    double num2;
    double num3;
    std:: cin >> num1;
    std:: cin >> num2;
    std:: cin >> num3;
    double average;


    average = (num1 + num2 + num3)/ 3;
    std:: cout << std:: fixed << std:: setprecision (4);
    std:: cout << "The average of "<< num1 <<", "<< num2 << ", and "<< num3 << " is " << average;


    return 0;
}