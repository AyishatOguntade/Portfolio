#include <iostream> 
#include <iomanip>

int main(){

    long int n;
    std:: cin >> n;
    long int sum = 0;

    while (n != 0){
        int digit = n % 10;
        if( digit % 2 == 0){
            sum = sum + digit;
            //std :: cout << digit;
        }
        n = n/ 10;
    }

    std:: cout << sum;


    return 0;
}