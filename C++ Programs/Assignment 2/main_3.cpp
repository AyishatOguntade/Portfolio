#include<iostream>
#include <vector>
// why is this printing a huge number 
int main(){

    int  n;
    std:: cin >> n;
    long int x = 2147483647;
    long int product = 1;

    for(int i =1; i <= n; i++){
        //std :: cout << product;
        if(product *i >= x){
            std:: cout << "Can't handle this";
            return 0;
        }
        else{
            product = product * i;
        }
    }


    std:: cout << product;


    return 0;
}