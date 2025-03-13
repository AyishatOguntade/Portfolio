#include <iostream>
#include <iomanip>

int main(){

int n;
std:: cin >> n;
int s;
std:: cin >> s;

int sum = 0;
int x = 0;
for(int i = n - s +1; x < s; x++){
    sum = sum +  i;
    i = i + 1;
    //std :: cout << i;
}
std :: cout << sum; 



    return 0;
}