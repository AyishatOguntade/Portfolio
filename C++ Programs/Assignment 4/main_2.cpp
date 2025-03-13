#include<iostream>
#include <string>
#include <sstream>
#include <vector>
// for input one line 
// contains number of rows, then collums, then number of generations 
// given me the patturn 
// comparing each cell with whats around it based on the rules

int CountLive(std:: vector <std::vector <char>>& board , int i , int j){
    int temp =0;
    // temp i and temp j
    if(i -1 >=0 && j-1>=0 && board[i-1][j-1] == '*' ){
        temp ++;
        //std:: cout << "left diagnol";
        //top left corner
    }
    if(j-1>=0 && board[i][j-1] == '*'){
        temp++;
        //std:: cout << "left neighbor";
    }
    if(i +1< board.size() && j-1>=0 && board[i+1][j-1]== '*'){
        temp++;
    }
    if(i -1>=0 && board[i-1][j]== '*'){
        temp++;
    }
    if(i +1 < board.size() && board[i+1][j]=='*'){
        temp++;
    }
    if( i -1>=0 && j +1 < board[0].size() && board[i-1][j+1] == '*'){
        temp++;
    }
    if(j +1 < board[0].size() && board [i][j+1] == '*'){
        temp++;
    }
    if(i +1< board.size() && j +1<board[0].size() && board[i+1][j+1] == '*'){
        temp++;
    }
    //
    return temp;
}


// returns a 2d vector with the new board from a generation  
std:: vector <std::vector <char>> NewBoard (std:: vector <std::vector <char>> board , int rows , int cols){
    //std:: cout <<"test0";
    std:: vector <std::vector <char>> newgrid = board;
    char dead = '.';
    //std:: cout << "test1";
    for(int i=0; i<rows; i++){
        for(int j=0; j< cols; j++){
            int temp = CountLive(board ,i, j);
            //call count live function and set that to temp 
            //dead rule
            if(board[i][j] == dead && temp == 3){
                newgrid[i][j] = '*';
            }
            //1. rule
            if(board[i][j] == '*'&& temp <2){
                newgrid[i][j] = '.';
            }
            //2.rule
            if(board[i][j] == '*'&& temp >3){
                newgrid[i][j] = '.';
            }
            //3 rule
            if(board[i][j] == '*' && temp ==2 || temp ==3 ){
                newgrid[i][j] = '*';
            }
            //std:: cout << "test2";
        }
        //std:: cout << "test3";
    }
    //std:: cout << "test4";
    return newgrid;
}



int main(){
    //std:: cout << "start";
    // get initial line and store the information
    std:: string line;
    std:: getline(std::cin,line);
    std:: istringstream inputStream(line);
    int rows;
    int cols;
    int gens;
    inputStream >>rows>>cols>> gens;
    // this works 
    std:: vector <std::vector <char>> board; 
    //std:: cout << "y";
    // save the start grid 
    for (int i = 0; i < rows; i++) {
        std:: vector <char> newRow;
        for (int j = 0; j < cols; j++) {
            char newVal;
            std:: cin >> newVal;
            newRow.push_back(newVal);
        }
        board.push_back(newRow);
    } 
    //std:: cout << gens;
    for(int k =0; k < gens; k++){
        board = NewBoard(board ,rows ,cols);
    }
    // print array for testing 
// Print array for testing
    for (int x = 0; x < rows; x++) {
        for (int y = 0; y < cols; y++) {
            std::cout << board[x][y];
            // Print a space if it's not the last element in the row
            if (y < cols - 1) {
                std::cout << " ";
            }
        }
        // Check if it's the last row before printing newline
        if (x < rows - 1) {
            std::cout << std::endl;
        }
    }



    //std:: cout << CountLive( board , 2 , 2);
    //std:: cout << board[2+1][2-1];

    return 0 ;
}