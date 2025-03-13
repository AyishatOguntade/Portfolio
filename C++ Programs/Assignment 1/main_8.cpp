#include <iostream>
#include <iomanip>

//use mod
// if number modded by 10 = 9 then its a good number 

 int main(){

    int num;

    std:: cin >> num;
    
    if(num % 10 == 9 || num %10 == -9){
        std:: cout << num << " is good";
    }
    else{
        std:: cout<< num << " is no good";
    }
    return 0; 
 }