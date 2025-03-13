#include <iostream> 
 #include <iomanip>

 int main(){

    int a;
    int b;
    std:: string z;
    std:: cin >> a; 
    std:: cin >> b;
    std:: cin >> z;

    int output = 0;

    if (z == "-"){
        output = a - b;
    }
    else if(z == "+"){
        output = a + b;
    }
    else if(z == "*"){
        output = a * b;
    }
    else{
        output = a / b;
    }

    std:: cout << a  <<" "<< z <<" "<< b << " = " << output;



    return 0;
 }