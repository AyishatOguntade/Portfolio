#include <iostream>
#include<string>
#include <sstream>
#include <vector>
// not sure on how to attempt this
// should i be removing all of the rules 
// Then storing them into difffrent strings
// Then comparing 
// or compare as i go

void plusFunction ( std::string *str){
    int plus_index = -1;
    int at_idx = -1;
    std:: string plus = "+";
    std:: string at = "@";
    for(int i=0; i < (*str).length(); i++){
        if( plus_index == -1 && (*str)[i] == plus[0]){
            plus_index = i;
        }
        if((*str)[i] == at[0]){
            at_idx = i;
        }
    }
    if(plus_index != -1 && at_idx !=-1){
    (*str).erase(plus_index,(at_idx - plus_index));
    }
}


int main(){
// how to handle exeption handing ???
    std::string input;
    std::getline(std::cin, input);

    std::istringstream inputStream(input);
    std::string email1, email2;
    inputStream >> email1 >> email2;

    //std::cout << "Email 1: " << email1 << std::endl;
    //std::cout << "Email 2: " << email2 << std::endl;

    std::string bEmail1 = email1;;
    std::string bEmail2 = email2;

    //std::string characters = ".";

    for(int i =0; i < bEmail1.length(); i++){
        if(bEmail1[i] == '.' ){
            bEmail1.erase(i,1);
            i--;
            //break;
            
        }
    }
        
    for(int x=0; x < bEmail2.length(); x ++){
        if(bEmail2[x] == '.'){
            bEmail2.erase(x,1);
            x--;
            //break;       
        }
    }

    
    //std:: cout << bEmail1 <<"before  "<<"\n";
    //std:: cout << bEmail2 <<"before  "<<"\n";
    plusFunction(&bEmail1);
    //std:: cout << bEmail1 <<"\n";
    plusFunction(&bEmail2);
    //std:: cout << bEmail2 << "\n";

    std:: string LEmail1;
    std:: string LEmail2;
    
    for(char c : bEmail1){
        c = std::tolower(c);
        LEmail1 = LEmail1 + c;
    } 
    for(char f : bEmail2){
        f = std::tolower(f);
        LEmail2 = LEmail2 + f;
    } 
    //plusFunction(&LEmail1);
    //plusFunction(&LEmail2);

    if(LEmail1 == LEmail2){
        std:: cout << "True";
    }
    else{
        std:: cout <<"False";
    }
    //std:: cout << bEmail1; 
    
    return 0;
}