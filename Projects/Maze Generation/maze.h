#ifndef MAZE
#define MAZE
#include<iostream>
#include<vector>
#include<string>
// creating the class maze 
class Maze{
    private:
        int rows;
        int cols;
        std::vector<std::vector<int>> mazeGrid; 

    public:
        //use this when inatalize the maze with the given n and m values 
        Maze(int n, int m);
        
        //use this to create the intal maze with the given n and m (rows ans cols)
        std::vector<std::vector<int>> initialMaze(int n, int m);

        //use this to save the Maze values to a file 
        void saveToFile(std::string &filename);
};

#endif
