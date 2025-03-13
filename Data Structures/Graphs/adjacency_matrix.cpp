#include "adjacency_matrix.h"
#include <iostream> 
#include <vector>
#include <fstream>

AdjMatrix::AdjMatrix(){
    this->source = 0;
    this->dest =  0;
    this->weight = 0;
    this->matrix = {};
}

void AdjMatrix::addEdge(int source, int dest, int weight) {
    // Ensure the matrix is large enough
    //whatver is the higher vaalcue could be the max size of the matrix
    int maxIndex = std::max(source, dest);
    if (maxIndex >= matrix.size()) {
        // Resize the matrix to accommodate new indices
        matrix.resize(maxIndex + 1, std::vector<int>(maxIndex + 1, 0));
        for (int i = 0; i < matrix.size(); i++) {
            matrix[i].resize(maxIndex + 1, 0); // Resize each row 
        }
    }
    // Add the edge
    matrix[source][dest] = weight;
}



void AdjMatrix::printGraph(){
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix.size(); j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

}
void AdjMatrix::outputGraph(std::string ofname){
    std::ofstream outFile(ofname);

    outFile << "digraph G {" << std::endl;
    outFile <<std::endl;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            if(matrix[i][j] != 0){
                outFile << "    " << i
                        << " -> " << j
                        << " [label=\"" << matrix[i][j] << "\"];" 
                        << std::endl;               
                }
        }
    }
    outFile << std::endl;
    outFile << "}" << std::endl;
    outFile.close();

}




