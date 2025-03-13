#include <iostream>
#include <iomanip>
#include<string>

// how to handle exeption handiling 
// will there be diffrent cases 

// possible done howver as about the exeption handling 
int main(){

    std:: string url;
    std:: getline (std::cin, url);
    std:: string domain;
    char x ='/';

    for(int i =0; i < url.length();i++){
        if(url[i]==x && url[i+1] == x){
            for(int j = i+2; j < url.length(); j++){
                if(url[j] != x && url[j] != ':'){
                    domain.push_back(url[j]);
                }
                else{
                    break;
                }
            //break;
            }

        }
    }
    //std:: cout << domain;
    std:: string Ldomain;
    for(char c : domain){
        c = std::tolower(c);
        Ldomain = Ldomain + c;
    }

    std:: cout << Ldomain;



    return 0;
}