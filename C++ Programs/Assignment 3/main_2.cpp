#include<iostream>
#include<iomanip>
#include <string>
#include <cstring>
// able toflip the line and see that 
// trying to figure out how to compare the two strings 
//works with Tacocat ex
int main(){

    std:: string line;
    std:: getline (std:: cin, line);
    std:: string reverseLine;
    //std:: string lowerline;

    std:: string Lline;
    for(char c : line){
        c = std::tolower(c);
        Lline = Lline + c;
    }

    for(int i = Lline.length()-1;i>=0 ; i--){
        reverseLine = reverseLine + Lline[i];
    }
    //std:: cout<< reverseLine;
    int x =0;
    //int z=reverseLine.length();
    //std:: cout << z;
    bool isP= true;
    for(; x < reverseLine.length() /2; x++){
        //std:: cout<< line[x]<<"\n" << reverseLine[x]<< '\n';
        if(Lline[x] != reverseLine[x]){
            isP = false;
            break;
        }
    }
    if(isP){
        std::cout<<"True";
    }
    else{
        std:: cout << "False";
    }
    //std:: cout << reverseLine;
    return 0;
}