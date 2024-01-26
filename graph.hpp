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
     * @brief adj is a vector of sets (to avoid repetitions) to represent adjacency matrix.
     */

    vector<set<int>> adj;
    /**
     * @brief V is the number of edges in the graph (+1 for convenience to avoid using 0 index).
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
     * @brief Construct a new Graph object with given number of edges.
     * 
     * @param maxNodeIncremented The number of edges in the graph  (+1 for convenience to avoid using 0 index).
     */
    Graph(int maxNodeIncremented);

    /**
     * @brief Adds an edge between two vertices in the graph.
     * 
     * @param u The source vertex.
     * @param v The destination vertex.
     */
    void addEdge(int u, int v);

    /**
     * @brief Finds cycles in the graph.
     *
     * This method performs a depth-first search to find cycles in the graph.
     * It starts the search from each vertex in the graph and keeps track of visited vertices and the current path.
     * If a cycle is found, it sets the `hasCycle` flag to true.
     *
     * @return void
     */
    void findCycles();

private:
    /**
     * @brief Finds cycles in the graph starting from a given node.
     * 
     * This function performs a depth-first search to find cycles in the graph
     * starting from the specified node. It uses a recursive approach to traverse
     * the graph and keeps track of visited nodes and the current path.
     * 
     * @param node The starting node for the search.
     * @param visited A vector indicating whether a node has been visited or not.
     * @param path A vector representing the current path in the graph.
     */
    void findCyclesUtil(int v, vector<bool>& visited, vector<int>& path);

    /**
     * @brief Prints the cycle starting from the given node.
     * 
     * This function prints the cycle starting from the given node by finding the path in the vector and 
     * extracting the cycle from it. The cycle is then sorted and printed to the console. If the cycle 
     * is not already present in the set of cycles, it is added to the set and the hasCycle flag is set 
     * to true.
     * 
     * @param path The vector containing the path.
     * @param node The starting node of the cycle.
     */
    void printCycle(vector<int>& path, int v);

};