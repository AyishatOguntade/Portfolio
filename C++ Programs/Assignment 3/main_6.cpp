#include <iostream>
//#include <vector>
#include<string>

int main(){

    std:: string line;
    std:: cout << "";
    std:: getline(std:: cin, line);
    int hashValue = 0;

    for(int i = 0; i < line.length(); i++){
        char x = line[i];
        hashValue = hashValue + static_cast <int> (x);
    }

    
    std:: cout << "" << hashValue << std::endl;

    return 0; 
}