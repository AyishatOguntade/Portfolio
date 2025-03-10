#include <iostream> 

bool prime_checker(int n , int d){
    if (n <= 1){
        return false;
    }               
    if (d * d > n){
        return true; 
    }
    if (n % d == 0){
        return false;
    }
    else{
        return prime_checker(n, d + 1);  
    }       

}

int main(int argc, char*argv[]){
    int num = std::stoi(argv[1]);
    int divisor = 2;
    bool val; 
    val = prime_checker(num, divisor);
    std:: cout<< val << std:: endl;
    return 0;
} 


