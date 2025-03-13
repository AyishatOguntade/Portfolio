#include <iostream>
#include <iomanip>

int main(){

double x;
double y;
std:: cin >> x;
std:: cin >> y;

if( x > 0 && y >0){
    std:: cout << "Quadrant 1";
}
else if(x < 0 && y > 0){
    std:: cout << "Quadrant 2";
}
else if (x < 0 && y < 0){
    std:: cout << "Quadrant 3";
}
else if (x > 0 && y < 0){
    std:: cout << "Quadrant 4";
}
else{
    std:: cout << "No quadrant";
}


    return 0;
}