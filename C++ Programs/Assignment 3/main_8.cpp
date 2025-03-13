#include <iostream>
#include <vector>
#include<string>
int main(){
// right idea but it needs work
// the issue is in the if statement 
//number is too high why is it counting that much 
//d
    std:: string word;
    std:: getline (std:: cin, word);
    int total = 0;
    std:: string newWord = "";
    //std:: cout<< word.length();
    for(int i =0;i< word.length(); i ++){
        char temp = word[i];
        bool isUnique = true;
        //std:: cout << temp << '\n';
        for(int j = 0; j < newWord.length(); j++){
            if(temp == newWord[j]){
                isUnique= false;
                //std:: cout<< word[j]<<'\n';
                //total = total;
            }
        }
        if(isUnique){
            //std:: cout << word[i];
            newWord = newWord + word[i];
            total = total + 1;
        }

    }

    std:: cout << total;




    return 0;
}