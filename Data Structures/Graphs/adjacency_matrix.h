#include <iostream> 
#include <vector> 

class AdjMatrix{

    private:
    int source;
    int dest;
    int weight;
    std::string ofname;
    std::vector<std::vector<int>> matrix ;

    public:
    // constuctor 
    AdjMatrix();
    // helper functions
    void addEdge(int source, int dest, int weight);
    void printGraph();
    void outputGraph(std::string ofname);
};
