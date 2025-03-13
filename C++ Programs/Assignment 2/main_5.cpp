#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    bool Prime = true;

    if (n <= 1) {
        Prime = false;
    } 
    else {
        for (int i = 2; i <= sqrt(n); ++i) {
            if (n % i == 0) {
                Prime = false;
                break;
            }
        }
    }

    if (Prime) {
        std::cout << "True";
    } else {
        std::cout << "False";
    }

    return 0;
}
