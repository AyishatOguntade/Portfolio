#include <iostream>
#include <iomanip>


int main(){

    int a;
    // the amount of stars to bring in 
    std:: cin>> a;
    int b; 
    // the max amount of stars in a single row (the num to go up to)
    std:: cin >> b;
    int c;
    // the number to  add by
    std:: cin >> c;
    int temp;
    for(int i = a; i <= b ; i = i +c){
        for(int j = 0; j < i ; j ++){
            std:: cout << "+";  
        }
        temp=i;
        std:: cout <<"\n";  
        //std:: cout << temp;      

    }
// flip it upside down 
    //int temp = a-1;
    for(int i = temp; i >= a ; i = i -c){
        for(int j = 0; j < i ; j ++){
            std:: cout << "+";  
        }
        temp = temp + c;
        std:: cout <<"\n";  
        //std:: cout << temp;      

    }
    return 0;
}