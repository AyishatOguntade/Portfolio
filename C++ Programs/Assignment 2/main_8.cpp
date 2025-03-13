#include <iostream>
#include <iomanip>

int main() {

    int n;
    std :: cin >> n; 

    if(n % 2 ==0){
        std :: cout << "Sorry, not odd";
        return 0;
    }
    else{
        // write code here to make pictures 
        // think about the stars and spaces try to find a patturn 
        int starCount = 0;
        for(int i = 0; i < n ; i ++){
            for( int j = 0 ; j <n ; j ++){
                if(i == j || j == (n -1 -i)){
                    std:: cout << "*";
                    starCount = starCount + 1;
                }
                else{
                    if(starCount < 2 && (i!= n/2)){
                        std:: cout << " ";
                    }
                    else{
                        if (starCount <1){
                            std:: cout << " ";
                        }
                    }

                }
               
            }
            std::cout << "\n";
            starCount = 0;
        }
    }


    return 0;
}