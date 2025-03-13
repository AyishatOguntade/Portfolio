#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

void display_board(int row, int col, const std::vector<std::vector<int>>& board) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Find low index values
std::pair<int, int> findLow(int rows, int cols, const std::vector<std::vector<int>>& board) {
    std::pair<int, int> temp(1, 1); // Start with 1-based indexing
    int minVal = board[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] < minVal) {
                minVal = board[i][j];
                temp.first = i + 1;  // Convert to 1-based index
                temp.second = j + 1;
            }
        }
    }
    return temp;
}

// Find high index values
std::pair<int, int> findHigh(int rows, int cols, const std::vector<std::vector<int>>& board) {
    std::pair<int, int> temp(1, 1); // Start with 1-based indexing
    int maxVal = board[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] > maxVal) {
                maxVal = board[i][j];
                temp.first = i + 1;  // Convert to 1-based index
                temp.second = j + 1;
            }
        }
    }
    return temp;
}

bool findPath(int rows, int cols, std::pair<int, int> start, std::pair<int, int> end, const std::vector<std::vector<int>>& board, std::vector<std::vector<bool>>& visited) {
    // Convert to 0-based index
    int startRow = start.first - 1;
    int startCol = start.second - 1;
    int endRow = end.first - 1;
    int endCol = end.second - 1;

    // Base case
    if (startRow == endRow && startCol == endCol) {
        return true;
    }

    // Mark start as visited
    visited[startRow][startCol] = true;

    // Up
    if (startRow > 0 && board[startRow - 1][startCol] >= board[startRow][startCol] && !visited[startRow - 1][startCol]){
        if (findPath(rows, cols, {startRow, startCol + 1}, end, board, visited)){
            return true;
        }
    }
    // Down
    if (startRow < rows - 1 && board[startRow + 1][startCol] >= board[startRow][startCol] && !visited[startRow + 1][startCol]){
        if (findPath(rows, cols, {startRow + 2, startCol + 1}, end, board, visited)){
            return true;
        }
    }
    // Left
    if (startCol > 0 && board[startRow][startCol - 1] >= board[startRow][startCol] && !visited[startRow][startCol - 1]){
        if (findPath(rows, cols, {startRow + 1, startCol}, end, board, visited)){
            return true;
        }
    }
    // Right
    if (startCol < cols - 1 && board[startRow][startCol + 1] >= board[startRow][startCol] && !visited[startRow][startCol + 1]){
        if (findPath(rows, cols, {startRow + 1, startCol + 2}, end, board, visited)){
            return true;
        }
    }

    return false;  
}

int main(int argc, char *argv[]) {
    
    std::string fname = argv[1];
    int rows = std::atoi(argv[2]);
    int cols = std::atoi(argv[3]);

    // start board
    std::vector<std::vector<int>> board(rows, std::vector<int>(cols, 0));

    // read in board from file
    std::ifstream inputFile(fname);
    std::string line1;
    int i = 0, temp1;
    while (std::getline(inputFile, line1)) {
        std::istringstream ss(line1);
        int j = 0;
        while (ss >> temp1) {
            board[i][j] = temp1;
            j++;
        }
        i++;
    }
    inputFile.close();

    // low and high points
    std::pair<int, int> lowIdx = findLow(rows, cols, board);
    std::pair<int, int> highIdx = findHigh(rows, cols, board);

    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
    bool pathExists = findPath(rows, cols, lowIdx, highIdx, board, visited);

    // output results
    std::cout << lowIdx.first << " " << lowIdx.second << " "
              << highIdx.first << " " << highIdx.second << " ";
    if (pathExists) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }

    return 0;
}

