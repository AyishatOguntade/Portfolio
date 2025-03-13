// vector of vecors
// use standard pair
#include "maze.h"
#include <iostream>
#include <vector>
#include <utility>
#include <fstream>

//create a maze with the given n and m
Maze::Maze(int n, int m){
    this-> rows = n;
    this-> cols = m;
    //std::cout <<"here" << std:: endl;
}
//create the inital maze filled with 15s and the start box of 7
// and exit 15
//use a vecor of vectors with the pairs++

//this function is creating the intial maze and returning that maze
// so will it need to not be a void function
std::vector<std::vector<int> > Maze::initialMaze(int n, int m) {
    this->rows = n;
    this->cols = m;
    this->mazeGrid = std::vector<std::vector<int> >(n, std::vector<int>(m, 15));

    //Set the start to 7 (top-left corner)
    if(n ==1 && m==1){
        mazeGrid[0][0] = 3;
    }
    else{
        mazeGrid[0][0] = 7;
        //Set the exit to 11 (bottom-right corner)
        mazeGrid[n - 1][m - 1] = 11;
    }
   
    //
    std::vector<std::pair<int, int> > path;
    path.push_back(std::make_pair(0,0));
    //int idx = std::rand() / ((RAND_MAX + 1u) / neighbors.size());
    //std::cout << idx;

    std::vector<std::vector<bool> > visited(n, std::vector<bool>(m, false));
    visited[0][0] = true;
    //std:: cout << "here2";

    while(!path.empty()){
        std::pair<int,int> current = path.back();
        int row = current.first;
        int col = current.second;
        std::vector<std::pair<int, int> > neighbors;
        path.pop_back();
        //do directions
        //figure out a way to mark as visited
        //north
        
        //check if the bounds checking is correct 
        //north
        if(row-1 >= 0 && !visited[row-1][col]){
            neighbors.push_back(std::make_pair(row-1,col));
        }
        //south
        if(row+1 < n &&!visited[row+1][col]){
            neighbors.push_back(std::make_pair(row+1,col));
        }
        //east
        if(col+1 < m &&!visited[row][col+1]){
            neighbors.push_back(std::make_pair(row,col+1));
        }
        //west
        if(col-1 >= 0 &&!visited[row][col-1]){
            neighbors.push_back(std::make_pair(row,col-1));
        }
        //eventually this will be the seed given by the command line
        //std::srand(seed);
        
        if (!neighbors.empty()) {
            // Push the current cell back onto the path
            path.push_back(current);

            // Randomly select a neighbor
            int idx = std::rand() / ((RAND_MAX + 1u) / neighbors.size());
            std::pair<int, int> neigh = neighbors[idx];

            // wall remove here 
            //mazegrid[neigh.first][neigh.second] = wall value
            //part thats random is the direction to go
            
            //remove north wall
            if(neigh.first + 1 == current.first){
                mazeGrid[current.first][current.second]-= 8; //remove top from current
                mazeGrid[neigh.first][neigh.second] -= 4; //remove bottom from neighbor above
            }
            //remove south wall
            if(neigh.first -1 == current.first){
                mazeGrid[current.first][current.second] -= 4; //remove bottom wall 
                mazeGrid[neigh.first][neigh.second] -= 8;//remove the top wall 
            }
            //remove the east wall
            if(neigh.second + 1 == current.second){
                mazeGrid[current.first][current.second]-=1; //remove right wall
                mazeGrid[neigh.first][neigh.second] -=2; // remove left wall
            }
            //remove west wall
            if(neigh.second - 1 == current.second){
                mazeGrid[current.first][current.second] -= 2; //remove left wall
                mazeGrid[neigh.first][neigh.second]-= 1;//remove right wall
            }


            visited[neigh.first][neigh.second] = true;
            // Mark the neighbor as visited ???- done
            //and push onto the path-done
            path.push_back(neigh);


        }


    }

    //print out the maze
    for(int i=0;i < n; i++){
        for(int j=0; j < m; j++){
            std:: cout << mazeGrid[i][j]<<" ";
        }
        std::cout << std::endl;
    }
    //Return the initialized maze
    return mazeGrid;
}

//write the numbers/maze to the given output filename
void Maze::saveToFile(std::string &filename){
    std::ofstream outFile(filename);
    for(int i=0; i < this -> rows; i++){
        for(int j=0; j< this -> cols; j++){
            outFile << this -> mazeGrid[i][j] << " ";
        }
        outFile <<std::endl;
    }
    outFile.close();
}



