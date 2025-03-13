#include "sudoku.h"
#include <sstream>
#include <fstream>
#include <iostream>

Sudoku::Sudoku() {

}

Sudoku::~Sudoku() {

}

Sudoku::Sudoku(std::string f_name) {
    // Generate a board from the give file
    std::ifstream inputFile(f_name);
    std::string line1;
    //std::getline(inputFile, line1);
    //std::istringstream iss(line1);
    unsigned int i = 0;
    
    unsigned int temp1;

    while(std::getline(inputFile, line1)) {
        std::istringstream ss(line1);
        unsigned int j = 0;
        while (ss >> temp1) {
            this->board[i][j] = temp1;
            j++;
        }
        i++; 
    }
   
    inputFile.close(); 


}

bool Sudoku::solve() {
    //base case if the whole board is filled 
    for(unsigned int row = 0; row < 9; row++){
        for(unsigned int col= 0; col < 9; col++){
            if(this->board[row][col] == 0){
                //try placing number 
                for(unsigned int num = 1; num <= 9; num++){
                    if(is_valid(row,col,num)){
                        this->board[row][col] = num;
                        if(solve()){
                            return true;
                        }
                        this->board[row][col] = 0;
                    }
                    //this->board[row][col] = 0;
                }
                return false;
            }
            //return false;
        }
        //return true;
    }

    return true;
}

// If this is an empty space & the given number does not exist in the same
// row, column, or box then it will return true.
bool Sudoku::is_valid(unsigned int row, unsigned int col, int num){
    return (this->board)[row][col] == 0
            && !check_row(row, num)
            && !check_col(col, num)
            && !check_box(row - row % 3, col - col % 3, num);
}

bool Sudoku::check_row(unsigned int row, unsigned int num){
    for(int j=0; j < 9; j++){
        if(board[row][j]== num){
            return true;
        }
    }

    return false;
}

bool Sudoku::check_col(unsigned int col, unsigned int num){
    for(int i=0; i < 9; i++){
        if(board[i][col]== num){
            return true;
        }
    }


    return false;
}

bool Sudoku::check_box(unsigned int boxStartRow, unsigned int boxStartCol, unsigned int num){
    for(unsigned int i = boxStartRow; i < boxStartRow + 3; i++){
        for(unsigned int j = boxStartCol; j< boxStartCol + 3; j++){
            if(board[i][j] == num){
                return true;
            }
        }
    }
    return false;
}

void Sudoku::display_board(){
    for (unsigned int i = 0; i < this->BOARD_SIZE; i++) {
        for (unsigned int j = 0; j < this->BOARD_SIZE; j++){
            std::cout << (this->board)[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char * argv[])
{
    std::string f_name(argv[1]);

    Sudoku s(f_name);

    s.solve();

    s.display_board();

    return 0;
}
