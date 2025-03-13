#include <iostream> 
#include <vector>
#include <utility>

class AdjList{

    private:

    int source;
    int dest;
    int weight;
    std::vector<std::vector<std::pair<int, int>>> list;

    public:
    // constructor 
    AdjList();
    // helper functions 
    void addEdge(int source, int dest, int weight);
    void printGraph();
    // just printing the normal list, includes, path destiantion and weight
    void problem1(std::string ofname);
    //the problems below focus on the diffrent color output
    void problem2(std::string ofname);
    void problem3(std::string ofname);
    //longest 
    // helper function 
    void dfs(int node, std::vector<bool>& visited, int depth, std::ofstream& outFile, const std::string colors[]);
    void problem4(std::string ofname);

};
