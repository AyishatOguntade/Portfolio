#include "maze.h"
#include<iostream>
#include<cstdlib>
//did i set the main correctly 
int main(int argc, char*argv[]){

    //get command line arguments 
    //remove these temp values before programing 
    int n;
    int m;
    int seed;
    std::string fname;
    //get the command line arguments 

    seed =std::stoi(argv[1]);
    n= std:: stoi(argv[2]);
    m =std:: stoi(argv[3]);
    fname =(argv[4]);
    
    //initalize random seed
    std::srand(seed);
    //std::vector<std::pair<int, int>> neighbors = {};
    //int idx = std::rand() / ((RAND_MAX + 1u) / neighbors.size());
    //std::cout << idx;
    Maze maze1(n,m);
    maze1.initialMaze(n,m);
    //save the maze to file
    maze1.saveToFile(fname);



    return 0;
}
