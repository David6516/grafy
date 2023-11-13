#include <vector>
#include <set>

using namespace std;

/**
 * @class Graph
 * @brief The Graph class represents an directed graph using adjacency list representation.
 * @details The class provides functionality to add edges to the graph and find cycles in it.
 * 
 * @author David Habryka
 */
class Graph {
    /**
     * @brief adj is a vector of vectors to represent adjacency matrix.
     */
    vector<vector<int>> adj;
    /**
     * @brief V is the number of vertices in the graph (+1 for convenience to avoid using 0 index).
     */
    int V;
    /**
     * @brief cycles is a set of vectors to store all cycles in the graph.
     */
    set<vector<int>> cycles;
    /**
     * @brief hasCycle is a boolean variable to check if the graph has any cycle or not.
     */
    bool hasCycle;

public:
    /**
     * @brief Construct a new Graph object with given number of vertices.
     * 
     * @param maxNodeIncremented The number of vertices in the graph  (+1 for convenience to avoid using 0 index).
     */
    Graph(int maxNodeIncremented);

    /**
     * @brief Add an edge to the graph.
     * 
     * @param u The source vertex of the edge.
     * @param v The destination vertex of the edge.
     */
    void addEdge(int u, int v);

    /**
     * @brief Find all cycles in the graph.
     */
    void findCycles();

private:
    //TODO: some private helper methods may need to be added here

};