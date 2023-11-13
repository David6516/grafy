#include <vector>
#include <set>

using namespace std;

class Graph {
    vector<vector<int>> adj;
    int V;
    set<vector<int>> cycles;
    bool hasCycle;

public:
    Graph(int maxNodeIncremented);

    void addEdge(int u, int v);
    void findCycles();

private:
};