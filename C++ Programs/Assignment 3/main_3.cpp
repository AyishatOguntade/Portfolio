#include<iostream>
#include<string>
//d
int main(){

std:: string line;
std:: getline (std:: cin, line);
//while (std::cin >> line) {
  // do something with value
//}
std:: string reverseLine;

for(int i = line.length()-1;i>=0 ; i--){
    reverseLine = reverseLine +line[i];
}

std:: cout << reverseLine;



    return 0;
}