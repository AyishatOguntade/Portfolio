//https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
#include "adjacency_list.h"
#include <iostream> 
#include <vector>
#include <fstream>


AdjList::AdjList(){
    this->source = 0;
    this->dest = 0; 
    this->weight =0;
    list = {};
}
// helper functions 
void AdjList::addEdge(int source, int dest, int weight) {
    // Ensure the list is large enough to accommodate source and destination
    int maxIndex = std::max(source, dest);
    if (maxIndex >= list.size()) {
        list.resize(maxIndex + 1);  // Resize the list to accommodate max index
    }

    // Add the edge to the adjacency list (source -> dest with weight)
    list[source].push_back(std::make_pair(dest, weight));
}

// Prints the adjacency list (graph representation)
void AdjList::printGraph() {
    // Iterate through the adjacency list and print edges
    for (int i = 0; i < list.size(); i++) {
        for (int j = 0; j < list[i].size(); j++) {
            std::pair<int, int> edge = list[i][j];
            std::cout << i << " -> " << edge.first
                      << " : " << edge.second << std::endl;
        }
    }
}


// list[i] << " -> " << list[i].first << " : "<< list[i].second<< std::endl;

// just printing the normal list, includes, path destiantion and weight
void AdjList::problem1(std::string ofname){
    //will this be the same as the dot visualization for the matrix???
    std::ofstream outFile(ofname);

    outFile << "digraph G {" << std::endl;
    outFile <<std::endl;
    for (int i = 0; i < list.size(); i++) {
        for (int j = 0; j < list[i].size(); j++) {
            int dest = list[i][j].first;      // Destination node
            int weight = list[i][j].second;  // Weight of the edge

            outFile << "    " << i << " -> " << dest
                    << " [label=\"" << weight << "\"];" 
                    << std::endl;
        }
    }

    outFile << std::endl;
    outFile << "}" << std::endl;
    outFile.close();
}
//the problems below focus on the diffrent color output
void AdjList::problem2(std::string ofname){
 //Color all edges with even weights blue and odd weights red 
 //and output the .dot file needed to visualize the graph   
    std::string colors[] = {"green", "blue", "red", "purple"};
    std::ofstream outFile(ofname);

    outFile << "digraph G {" << std::endl;
    outFile <<std::endl;
    for (int i = 0; i < list.size(); i++) {
        for (int j = 0; j < list[i].size(); j++) {
            int dest = list[i][j].first;      // Destination node
            int weight = list[i][j].second;  // Weight of the edge
            std::string color;

            if (weight % 2 == 0) {
                color = "blue";  // Even weights are blue
            } else {
                color = "red";   // Odd weights are red
            }

            outFile << "    " << i << " -> " << dest
                    <<" [label=\"" << weight << "\"]" 
                    <<"[color=\"" << color << "\"];"
                    << std::endl;
        }
    }

    outFile << std::endl;
    outFile << "}" << std::endl;
    outFile.close();

}
void AdjList::problem3(std::string ofname) {
    std::ofstream outFile(ofname);
    std::string colors[] = {"green", "blue", "red", "purple"};

    outFile << "digraph G {" << std::endl;
    outFile << std::endl;
    for (int i = 0; i < list.size(); i++) {
        int position = 0;
        for (int j = 0; j < list[i].size(); j++) {
            std::pair<int, int> edge = list[i][j];
            std::string color = colors[position % 4];
            outFile << "    " 
            << i << " -> " << edge.first 
            << " [label=\"" << edge.second << "\"]" 
            <<"[color=\"" << color << "\"];" << std::endl;
            position++;
        }
    }
    outFile << std::endl;
    outFile << "}" << std::endl;

    outFile.close();
}
//longest 
void AdjList::dfs(int node, std::vector<bool>& visited, int depth, std::ofstream& outFile, const std::string colors[]) {
    visited[node] = true;  // Mark the current node as visited

    for (int i = 0; i < list[node].size(); i++) {  
        std::pair<int, int> edge = list[node][i]; 
        std::string color = colors[depth % 4];  // Choose a color based on the depth

        // Write edge in the specified format
        outFile << "  " << node << " -> " << edge.first
                << " [label=\"" << edge.second << "\"][color=\"" << color << "\"];" 
                << std::endl;

        // Recursively visit the destination node if it hasn't been visited
        if (!visited[edge.first]) {
            dfs(edge.first, visited, depth + 1, outFile, colors);
        }
    }
}

void AdjList::problem4(std::string ofname){
//
//Color all edges based on their distance from the root node and output the 
//.dot file needed to visualize the graph (Hint: Use depth-first search!)
    std::ofstream outFile(ofname);  // Open the output file
    std::string colors[] = {"green", "blue", "red", "purple"};  
    std::vector<bool> visited(list.size(), false);  // Track visited nodes

    outFile << "digraph G {" << std::endl; 
    outFile <<std::endl; 
    dfs(0, visited, 0, outFile, colors);    // Start from node 0
    outFile << std::endl;
    outFile << "}" << std::endl;      

    outFile.close();  // Close the file
}



