#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <utility>  
#include <tuple>    

using namespace std;

struct Graph {
    int n;  
    vector<vector<bool>> adj_m;  // Adjacency matrix (1-based)

    Graph(int vertices) : n(vertices), adj_m(vertices + 1, vector<bool>(vertices + 1, false)) {}
}; 

// Function to read input from the file and return n, m, and list of edges
tuple<int, int, vector<pair<int, int>>> read_input(const string& filename) {
    ifstream input(filename);
    if (!input.is_open()) {
        cerr << "Error opening input file: " << filename << endl;
        return {0, 0, {}};
    }

    int n, m;
    input >> n >> m;
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
        input >> edges[i].first >> edges[i].second;
    }
    input.close();

    return {n, m, edges};
}

// Function to build graph from edges
Graph build_graph_from_edges(int n, const vector<pair<int, int>>& edges) {
    Graph g(n);
    for (const auto& e : edges) {
        g.adj_m[e.first][e.second] = true;
        g.adj_m[e.second][e.first] = true;  // Undirected
    }
    return g;
}

// Function to find spanning tree using BFS algorithm
// Returns list of edges in the spanning tree
vector<pair<int, int>> find_spanning_tree(const Graph& g) {
    vector<bool> visited(g.n + 1, false);  // 1-based
    queue<int> q;

    // Start BFS from vertex 1 (assuming connected)
    q.push(1);
    visited[1] = true;

    vector<pair<int, int>> tree_edges;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 1; v <= g.n; ++v) {
            if (g.adj_m[u][v] && !visited[v]) {
                visited[v] = true;
                q.push(v);
                tree_edges.emplace_back(u, v);  // Add edge (u, v) to tree
            }
        }
    }

    return tree_edges;
}

void write_output(const string& filename, const vector<pair<int, int>>& tree_edges) {
    ofstream output(filename);
    if (!output.is_open()) {
        cerr << "Error opening output file: " << filename << endl;
        return;
    }

    for (const auto& e : tree_edges) {
        output << e.first << " " << e.second << endl;
    }
    output.close();
}

int main() {
    auto [n, m, edges] = read_input("INPARBGRAPH.TXT");
    if (n == 0) {
        return 1;  
    }

    if (n > 1000 || m > (n * (n - 1) / 2)) {
        cerr << "n or m out of bounds" << endl;
        return 1;
    }
    for (const auto& e : edges) {
        if (e.first < 1 || e.first > n || e.second < 1 || e.second > n) {
            cerr << "Vertex index out of range" << endl;
            return 1;
        }
    }

    Graph g = build_graph_from_edges(n, edges);
    auto tree_edges = find_spanning_tree(g);
    write_output("OUTARBGRAPH.TXT", tree_edges);

    cout << "Spanning tree written to OUTARBGRAPH.TXT." << endl;

    return 0;
}