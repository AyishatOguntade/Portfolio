#include <iostream>
#include <string>
#include <iomanip>
// watched a video about strings in c ++
int main() {
    int r, g, b;
    std::cin >> r >> g >> b;

    std::string hexChars = "0123456789ABCDEF";
    std::string hexR = "";
    std::string hexG = "";
    std::string hexB = "";

   
    hexR = hexR + hexChars[r / 16];
    hexR = hexR + hexChars[r % 16];

   
    hexG = hexG + hexChars[g / 16];
    hexG = hexG + hexChars[g % 16];

    
    hexB = hexB + hexChars[b / 16];
    hexB = hexB + hexChars[b % 16];

    std::cout << "#" << hexR << hexG << hexB << std::endl;

    return 0;
}
