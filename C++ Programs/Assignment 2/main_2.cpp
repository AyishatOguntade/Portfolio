#include <iostream>
// need help on 

int main(){
    int num;


    std::cin >> num;


    for(int i = 1; i <= num; ++i){

        for(int k = 1; k <= num- i ; ++k){
            std::cout << " ";
            //spaces
        }
        for(int j = 1; j <= i ; ++j){
            std::cout << "*";
            // stars 
        }
        std::cout << "\n";
    }


    return 0;
}
