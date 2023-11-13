#include "graph.hpp"
#include <iostream>

using namespace std;

Graph::Graph(int maxNodeIncremented) /*: V(maxNodeIncremented), adj(maxNodeIncremented), hasCycle(false)*/ {
    adj.resize(maxNodeIncremented);
}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);

    // only for debugging, will be removed later
    cout << "Added edge from " << u << " to " << v << endl;
    cout << "Current adj list for " << u << ": ";

    for (int i : adj[u]) {
        cout << i << " ";
    }
    
    // for (int j = 0; j < adj[u].size(); j++) {
    //     cout << adj[u][j] << " ";
    // }
 
    cout << endl;
}



void Graph::findCycles() {
    cout << "This will search for cycles, but is only stub for now..." << endl;
}
