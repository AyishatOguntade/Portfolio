#include <iostream>
#include <iomanip>

int main(){

double inputTemp;
std:: cin >> inputTemp;
std:: string type;
std:: cin >> type;

double Ftemp;
double Ctemp;

//Ftemp =(Ctemp)*(9/5) + 32;
//Ctemp =(Ftemp -32)* 5/9;

if(type == "C"){
    std:: cout << std:: fixed << std:: setprecision (4);
    Ftemp = (inputTemp)*(9.0/5.0) + 32;
    std:: cout << inputTemp << " degree(s) "<<type << " is equal to " << Ftemp << " degree(s) F";
}
else{
    std:: cout << std:: fixed << std:: setprecision (4);
    Ctemp = (inputTemp -32)* 5.0/9.0;
    std:: cout << inputTemp << " degree(s) "<<type << " is equal to " << Ctemp << " degree(s) C";
}

    
    return 0;
}