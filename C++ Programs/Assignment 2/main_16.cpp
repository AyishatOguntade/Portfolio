#include<iostream>
#include <iomanip>
#include <vector>
#include <cmath>
int main(){
    int num;
    std:: cin>> num;
    std:: vector <int> rotations;

    int temp = num;
    int numDigits = 0;

    // Count number of digits
    while (temp != 0) {
        numDigits = numDigits + 1;
        temp /= 10;
    }

    // Rotate digits
    for (int i = 0; i < numDigits; i++) {
        int lastDigit = num % 10;
        int restOfDigits = num / 10;
        num = lastDigit * pow(10, numDigits - 1) + restOfDigits;
        rotations.push_back(num);
    }

    int x = rotations.size();
    int z = 0;

    for (int j = 0; j < x; j++) {
        int p = 0;
        for (int a = 2; a <= sqrt(rotations[j]); a++) {
            if (rotations[j] % a == 0) {
                z = z + 1;
                p = p + 1;
            }
        }
        if (p == 0) {
            z = z + 1;
        }
    }

    if (z == x && num >= 2) {
        std::cout << "True";
    } else {
        std::cout << "False";
    }
    return 0;
}