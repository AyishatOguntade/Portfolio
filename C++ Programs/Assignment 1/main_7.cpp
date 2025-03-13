#include <iostream>
#include <iomanip>

int main(){
// use mod
//if any number mod 8 has a remander of zero then that makes it a multiple of 8 

int num;

std:: cin >> num; 

if(num > 100 && num % 8 == 0){
    std::cout << num << " satisfies the criteria";
}
else{
    std:: cout << num << " does not satisfy the criteria";
}

return 0;

}