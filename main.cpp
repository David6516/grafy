#include <iostream>
#include <fstream>
#include <sstream>

#include "graph.hpp"

using namespace std;

int main() {
    ifstream file("edges.txt");
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