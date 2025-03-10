#include <iostream>
int gcd(int num1, int num2){
    if(num1 == 0){
        return num2;
    }
    if(num2 == 0){
        return num1;
    }
    if(num1== num2){
        return num1;
    }
    if(num1 >num2){
        return gcd(num1%num2, num2);
    }
    if(num2> num1){
        return gcd(num1, num2%num1);
    }
    return 0;
}

int main(int argc, char*argv[]){
    int num1 = std::stoi(argv[1]);
    int num2 = std::stoi(argv[2]);
    int val;
    val = gcd(num1,num2);
    std:: cout << val << std::endl;
    return 0;
} 
