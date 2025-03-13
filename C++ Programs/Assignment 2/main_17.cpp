#include<iostream>
#include <iomanip>

int main(){

    int x;
    int y;
    std:: cin >> x;
    std :: cin >> y;
    int move ;

    while( std:: cin >> move){

        switch (move){
            case 0:
                y = y +1; 
                x  = x +2;
             break;
            
            case 1:
                y = y -1;
                x= x +2;
            break;

            case 2:
                y = y -2; 
                x = x +1;
                break;
            
            case 3:
                y = y -2;
                x = x -1;
                break;
            
            case 4:
                y = y -1;
                x = x-2;
                break;
            
            case 5:
                y = y + 1;
                x = x -2;
                break;
            
            case 6:
                y = y +2;
                x = x -1;
                break;

            case 7: 
                y = y +2;
                x = x +1;
                break;

        }
        //std:: cout << x << y << std::endl;
        //std :: cout << move <<"$";
        if( x >8 || y >8 || x < 1 || y < 1 ){
            //std:: cout << x << y;
            std:: cout <<"Invalid sequence";
            return 0;
        }
        
    }
    std:: cout << x  <<" "<< y;

    return 0;
}