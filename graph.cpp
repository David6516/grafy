#include "graph.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

Graph::Graph(int maxNodeIncremented) : V(maxNodeIncremented), adj(maxNodeIncremented), hasCycle(false) {

    // V = maxNodeIncremented;
    // adj = vector<vector<int>>(maxNodeIncremented);
    // hasCycle = false;
}

void Graph::addEdge(int u, int v) 
{
    adj[u].insert(v);

    // only for data structure analysis, will be removed later
    // cout << "Added edge from " << u << " to " << v << endl;
    // cout << "Current adj list for " << u << ": ";
    // for (int i : adj[u]) {
    //     cout << i << " ";
    // }
    // cout << endl;
}


void Graph::findCycles() {
    vector<bool> visited(V, false);
    vector<int> path;

    for (int i = 1; i <= V; i++) {
        findCyclesUtil(i, visited, path);
    }

    if (!hasCycle) {
        cout << "No cycles found.\n";
    }
}

void Graph::findCyclesUtil(int node, vector<bool> &visited, vector<int> &path)
{
    visited[node] = true;
    path.push_back(node);

    for (int i : adj[node]) {
        if (!visited[i]) {
            findCyclesUtil(i, visited, path);
        } else if (find(path.begin(), path.end(), i) != path.end()) {
            printCycle(path, i);
        }
    }

    path.pop_back();
    visited[node] = false;
}

void Graph::printCycle(vector<int>& path, int v) {
    auto it = find(path.begin(), path.end(), v);
    vector<int> cycle(it, path.end());
    
    // this is wrong !!!
    //sort(cycle.begin(), cycle.end());

    // Rotate the cycle so that the smallest element is first
    rotate(cycle.begin(), min_element(cycle.begin(), cycle.end()), cycle.end());

    if (!cycles.count(cycle)) {
        cycles.insert(cycle);
        if (!hasCycle) {
            cout << "Cycle(s) found:\n";
            hasCycle = true;
        }
        for (int i : cycle) {
            cout << i << ' ';
        }
        cout << '\n';
    }
}
