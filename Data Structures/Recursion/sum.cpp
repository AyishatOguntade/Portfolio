#include <iostream>

int sum(int n);

int main(int argc, char*argv[]){
    int num = 10;
    
    std::cout << sum(num) << std::endl;
}

int sum(int n){
    if (n == 0) {
    return 0;
    }
    unsigned long sub_sum = sum(n - 1);
    unsigned long total = n + sub_sum;
    return total;
}
