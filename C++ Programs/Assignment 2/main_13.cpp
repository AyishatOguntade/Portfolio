#include <iostream>
#include <iomanip> 
#include <vector>
#include <cmath>
int main(){

int n;
std:: cin >> n;
int z = n;
std:: vector <int> digits;

while(n > 0){
    int digit = n %10;
    digits.push_back(digit);
    n = n/ 10;
    //std:: cout << digit;
}
int total = 0;
int ex = digits.size();
for(int num : digits){
    total = total + pow(num, ex);
}

if( total == z){
    std:: cout << "True";
}
else{
    std:: cout<< "False";
}


    return 0; 
}