#include<iostream>

void print(int disk, int from , int to){
    std::cout << "Move disk " << disk << " from tower " << from << " to tower " << to << std::endl;
}
void hanoi(int n, int start,int end){
    if(n == 1){
        print(n,start,end);
    }
    else{
        int middle = 6 - (start + end);
        hanoi(n-1, start, middle);
        print(n,start,end);
        hanoi(n-1, middle , end);
    }
}
int main(int argc, char*argv[]){
    int n = std::stoi(argv[1]);
    int start = std::stoi(argv[2]);
    int end = std::stoi(argv[3]);
    hanoi(n,start,end);
    return 0;
} 

