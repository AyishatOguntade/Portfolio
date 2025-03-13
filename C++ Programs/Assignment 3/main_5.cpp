#include <iomanip>
#include <iostream>
#include <string>
//d
int main(){

    std:: string line;
    std:: getline (std:: cin, line);
    std:: string newLine;

    for(int i =0; i < line.length(); i++){
        if(line[i] != line[i+1]){
            newLine = newLine + line[i];
        }
        else{
            newLine = newLine;
        }
    }
    std:: cout << newLine;


    return 0;
}