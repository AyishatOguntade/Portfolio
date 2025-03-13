#include <iostream>
#include <iomanip>
#include <vector>
int main(){

    int n;
    std:: cin >> n;
    int k;
    std:: cin >> k;
    
    long int pow =1;

    for(int i = 0; i < k; i++ ){
        pow = pow * n;
        
    }
    
    std :: cout << pow;


    return 0;
}