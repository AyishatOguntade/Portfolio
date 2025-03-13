#include <iostream>
#include <iomanip>

int main(){

    int a;
    int b;
    int c;
    std :: cin >> a;
    std :: cin>> b;
    std :: cin>> c;
    int smallestNum = 0;

    if(a < b && a < c){
        smallestNum = a;
    }
    else if (b < a && b < c){
        smallestNum = b;
    }
    else{
        smallestNum = c;
    }

    std:: cout<< "The smallest number entered was " <<smallestNum;


    return 0;
}