#include <iostream>
#include <iomanip>

int main(){

double startLoan; 
std:: cin>> startLoan;
double intrest;
std:: cin >> intrest;
double payment;
std:: cin >> payment;

int months = 0;

while (startLoan >0){
    double interest2 = startLoan * intrest;
    //std:: cout << interest2;
    startLoan = startLoan + interest2 - payment;
    months = months + 1;
}

std:: cout << months;

    return 0;
}