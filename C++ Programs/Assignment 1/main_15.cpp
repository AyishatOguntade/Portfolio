#include <iostream>
#include <iomanip>

int main(){

    double Ctemp;
    std:: cin >> Ctemp;
    double Ftemp;
    Ftemp = (Ctemp)*(9.0/5.0) + 32;

    if(Ftemp <= 32){
        std:: cout << "It is cold out";
    }
    else if( Ftemp > 32 && Ftemp <= 65){
        std:: cout << "Wear a jacket";
    }
    else{
        std:: cout << "It is nice out";
    }


    return 0;
}