#include <iostream>
#include <iomanip>

int main(){

int side1;
int side2;
int side3;
std:: cin >> side1;
std:: cin >> side2;
std:: cin >> side3;

if(side1 + side2 +side3 != 180){
    std:: cout << "This triangle is impossible";
}
else if(side1 == 90 || side2 == 90 || side3 == 90){
    std:: cout <<"Right";
}
else if( side1 >90 || side2 >90 || side3 >90){
    std:: cout << "Obtuse";
}
else{
    std:: cout << "Acute";
}


    return 0;
}