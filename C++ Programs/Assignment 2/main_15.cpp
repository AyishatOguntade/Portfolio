#include <iostream>

int main() {
    int n;
    std::cin >> n;

    std::cout << "#";
    for (int i = 0; i < (n * 4); i++) {
        std::cout << "=";
    }
    std::cout << "#" << std::endl;

    for (int row = 0; row < n; row++) {
        std::cout << "|";
        for (int space = 0; space < ((n * 4) - 4) / 2 - (row * 2); space++) {
            std::cout << " ";
        }
        std::cout << "<>";
        for (int dot = 0; dot < (4 * row); dot++) {
            std::cout << ".";
        }
        std::cout << "<>";
        for (int space = 0; space < ((n * 4) - 4) / 2 - (row * 2); space++) {
            std::cout << " ";
        }
        std::cout << "|\n";
    }

    for (int row = (n -1); row >= 0; row--) {
        std::cout << "|";
        for (int space = 0; space < ((n * 4) - 4) / 2 - (row * 2); space++) {
            std::cout << " ";
        }
        std::cout << "<>";
        for (int dot = 0; dot < (4 * row); dot++) {
            std::cout << ".";
        }
        std::cout << "<>";
        for (int space = 0; space < ((n * 4) - 4) / 2 - (row * 2); space++) {
            std::cout << " ";
        }
        std::cout << "|\n";
    }

    std::cout << "#";
    for (int i = 0; i < (n * 4); i++) {
        std::cout << "=";
    }
    std::cout << "#" << std::endl;

    return 0;
}