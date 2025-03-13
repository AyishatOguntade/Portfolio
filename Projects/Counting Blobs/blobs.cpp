#include <iostream>
#include <fstream>
#include <cstdlib> 

class Cellgrid {
private:
    bool *grid;
    int rows;
    int cols;

public:
    // Constructor reads a file and initializes the grid
    Cellgrid(const char *fname, int m, int n) {
        rows = m;
        cols = n;
        grid = new bool[rows * cols];

        std::ifstream infile(fname);
        for (int i = 0; i < rows; i++) {
            int base = i * cols;
            for (int offset = 0; offset < cols; offset++) {
                infile >> grid[base + offset];
            }
        }
        infile.close();
    }

    // Destructor to free allocated memory
    ~Cellgrid() {
        delete[] grid;
    }

    //refrence 211 assignment 5
    int countCells(int row, int col, int conn) {
        if(row<1 ||col <1 || row  >=rows +1 || col >= cols +1 || grid[((row-1)*cols) +(col-1)] ==0 ){
        return 0;
    }
        grid[((row-1)*cols) +(col-1)]=0;
        //std:: cout << grid[((row-1)*cols) +(col-1)]<< std:: endl;
        int count =1;
        if(conn == 4){
            return 1+(countCells( row-1,col,conn) + countCells(row +1, col,conn) + countCells(row, col-1,conn) + countCells(row,col+1,conn));
        }
        if (conn ==8){
            return 1+(countCells( row-1,col,conn)+ countCells(row +1, col,conn) + countCells(row, col-1,conn) + countCells(row,col+1,conn)
            +countCells(row-1,col-1,conn) + countCells(row+1,col+1,conn)+ countCells(row-1,col+1,conn) + countCells(row+1,col-1,conn))
            ;
            // add whats above then add 4 more changinig both 
        }
        return 0;
    }

    // Counts the number of blobs in the grid
    int countBlobs(int conn) {
        int blobs =0;
        for(int i=0; i < (rows*cols); i++){
            if(grid[i] == 1){
                blobs++;
                countCells((i/cols)+1, (i%cols) +1, conn);
            }
        }
        return blobs;
    }

    // Prints the grid for debugging purposes
    void print() {
        for (int i = 0; i < rows; i++) {
            int base = i * cols;
            std::cout << grid[base];
            for (int offset = 1; offset < cols; offset++) {
                std::cout << ' ' << grid[base + offset];
            }
            std::cout << std::endl;
        }
    }
};

int main(int argc, char *argv[]) {

    const char *filename = argv[1];
    int rows = std::atoi(argv[2]);
    int cols = std::atoi(argv[3]);
    int conn = std::atoi(argv[4]);

    // Create a Cellgrid object
    Cellgrid cellgrid(filename, rows, cols);

    // Count blobs and print the result
    int blobCount = cellgrid.countBlobs(conn);
    std:: cout << blobCount <<std::endl;

    return 0;
}

