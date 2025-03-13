#include "sujiko.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>

Sujiko::Sujiko() {
}

Sujiko::Sujiko(std::string fname) {
    // Open the input file
    std::ifstream inputFile(fname);

    // Read the first line for the 4 sum values
    std::string line1;
    std::getline(inputFile, line1);
    std::istringstream iss(line1);
    unsigned int num;
    std::vector<unsigned int> temp;
   
    // Parse the first 4 numbers for the sum values
    while (iss >> num) {
        temp.push_back(num);
    }
   
    // Assign the first 4 numbers to the nums 2x2 array
    this->nums[0][0] = temp[0];
    this->nums[0][1] = temp[1];
    this->nums[1][0] = temp[2];
    this->nums[1][1] = temp[3];
   
    // Print the sum values to check 
    /*
    std::cout << "Sum values:" << std::endl;
    for (unsigned int z = 0; z < 2; z++) {
        for (unsigned int y = 0; y < 2; y++) {
            std::cout << nums[z][y] << " ";
        }
        std::cout << std::endl;
    }
    */

    // Read the board values from the file
    std::string line2;
    unsigned int temp1;
    unsigned int k = 0;
    unsigned int u = 0;

    while (std::getline(inputFile, line2)) {
        std::istringstream ss(line2);
        while (ss >> temp1) {
            this->board[k][u] = temp1;
            u++;
        }
        u = 0;  // Reset column index
        k++;    // Move to the next row
    }
   
    inputFile.close(); 
}

Sujiko::~Sujiko() {
}

// Function to check if the sum conditions are met
bool Sujiko::sumLines() {
    if (board[0][0] + board[0][1] + board[1][0] + board[1][1] != nums[0][0]) {
        return false;
    }
    if (board[0][1] + board[0][2] + board[1][1] + board[1][2] != nums[0][1]) {
        return false;
    }
    if (board[1][0] + board[1][1] + board[2][0] + board[2][1] != nums[1][0]) {
        return false;
    }
    if (board[1][1] + board[1][2] + board[2][1] + board[2][2] != nums[1][1]) {
        return false;
    }

    return true;
}

// Function to check if a number can be placed without duplication
bool Sujiko::original_grid(int num) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (this->board[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

// Function to solve the puzzle using backtracking
bool Sujiko::solve(unsigned int cell) {
    // If we've filled all cells, we're done(base case)
    if (cell == BOARD_SIZE * BOARD_SIZE) {
        return true;
    }

    // Calculate row and column for the current cell
    int row = cell / BOARD_SIZE;
    int col = cell % BOARD_SIZE;

    // If the current cell already has a value, go to next
    if (this->board[row][col] != 0) {
        return solve(cell + 1);
    }

    // Try placing numbers 1-9 
    for (int i = 1; i <= 9; i++) {
        if (original_grid(i)) {  
            this->board[row][col] = i; 
            if (solve(cell + 1) && sumLines()) {
                return true;
            }
        }

        //put it back if its not valid
        this->board[row][col] = 0;
    }

    return false; 
}

void Sujiko::display_board() {
    for (unsigned int i = 0; i < this->BOARD_SIZE; i++) {
        for (unsigned int j = 0; j < this->BOARD_SIZE; j++) {
            std::cout << this->board[i][j] << " "; 
        }
        std::cout << std::endl;
    }
}

int main(int argc, char *argv[]) {
    Sujiko s(argv[1]);

    s.solve(0);

    s.display_board(); 

    return 0;
}
