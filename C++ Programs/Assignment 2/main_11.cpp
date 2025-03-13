#include <iostream>
#include <iomanip>
// need help on what the questions is asking
// will it ask for diffrent letters
// is this the only test case 
// draw a chart in figure out when it prints and a ,b ,c and space 
int main(){

char ch; 
std:: cin >> ch;
char ch2;

for (int i = 65; i <= ch; i++) { 
    // Control the number of rows
    // Print spaces to center the triangle of numbers
    for (int j = 0; j < (ch - i); j++) {
         std::cout << "  ";
    }
    for(int z = 65; z <= i; z ++){
        ch2 = z;
        if( i == 65){
            std:: cout <<ch2;
        }
        else{
            std :: cout << ch2<<" ";  
        }  
    }


    for(int z = i-1; z >= 65; z --){
        ch2 = z;
        if ( z == 65){
            std :: cout << ch2; 
        }
        else{
            std :: cout << ch2 << " ";
        }
    }
    std:: cout << "\n";


}
return 0;
}