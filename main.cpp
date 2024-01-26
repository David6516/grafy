#include <iostream>
#include <fstream>
#include <sstream>

#include "graph.hpp"

using namespace std;

/**
 * @brief The main function reads a file with edges and creates a graph. 
 * It then finds all cycles in the graph and prints them to the console (not implemented yet)
 * 
 * @return int 
 */
int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: ./program <filename>" << endl;
        return 1;
    }

    string filename = argv[1];
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open file: " << filename << endl;
        return 1;
    }
    string line;
    int maxNode = 0;

    while (getline(file, line)) {
        istringstream iss(line);
        int node1, node2;
        string arrow;
        iss >> node1 >> arrow >> node2;
        maxNode = max(maxNode, max(node1, node2));
    }

    file.clear();
    file.seekg(0, ios::beg);

    Graph g(maxNode + 1);

    while (getline(file, line)) {
        istringstream iss(line);
        int node1, node2;
        string arrow;
        iss >> node1 >> arrow >> node2;
        if (arrow == "->") {
            g.addEdge(node1, node2);
        } else if (arrow == "<-") {
            g.addEdge(node2, node1);
        }
    }

    g.findCycles();

    return 0;
}