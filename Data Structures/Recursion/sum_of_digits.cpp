#include<iostream>

int sum_of_digits(int num){
    if(num < 10){
        return num;
    }
    int sum;
    sum = (num % 10) + sum_of_digits( num / 10);
    return sum;
}

int main(int argc, char*argv[]){
    int num = std::stoi(argv[1]);
    int val;
    val= sum_of_digits(num);
    std::cout << val << std::endl;

    return 0;
}
    

