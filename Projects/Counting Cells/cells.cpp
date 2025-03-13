#include <iostream>
#include <fstream>
#include <sstream>
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
};

int main(int argc, char*argv[]){
    //get command line arguments 
    const char *fname = argv[1];
    int m = std:: stoi(argv[2]);//rows
    int n = std:: stoi(argv[3]);//cols
    int x = std::stoi(argv[4]);//row of starting cell
    int y = std::stoi(argv[5]);//col of starting cell
    int conn = std:: stoi(argv[6]);// connection type 4 or 8

    Cellgrid cellgrid(fname, m, n);
    //cellgrid.countCells(x,y,conn);
    // my problem is most likey due to me not usinf x or y 
    int cellCount = cellgrid.countCells(x,y,conn);
    std:: cout << cellCount<<std::endl;

    return 0;
}
