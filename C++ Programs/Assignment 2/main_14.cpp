#include <iostream>
#include <iomanip>
#include <vector>

int main(){

    int n;
    std :: cin >> n;
    std:: vector <int> divisors;
    int z = 0;

    for(int i=1; i<n ; i ++){
        if(n% (n-i) == 0){
            divisors.push_back(n-i);
        }
        else{
            z=z+1;
        }
    }
    int sum =0;
    for(int num : divisors){
        sum = sum + num;
    }

    if(sum == n){
        std:: cout << "True";
    }
    else{
        std:: cout << "False";
    }




    return 0;
}