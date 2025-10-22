#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

void question_5_1(ifstream &fin, ofstream &fout) {
    fout << "=== Question 5.1 : Dijkstra avec matrice d'adjacence ===\n";

    int n, m, start, dest;
    fin >> n >> m >> start >> dest;

    vector<vector<int>> adj(n + 1, vector<int>(n + 1, INF));
    for (int i = 0; i < m; ++i) {
        int u, v, w; fin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w;
    }

    vector<int> dist(n + 1, INF), parent(n + 1, -1);
    vector<bool> vis(n + 1, false);
    dist[start] = 0;

    for (int i = 1; i <= n; ++i) {
        int u = -1;
        for (int j = 1; j <= n; ++j)
            if (!vis[j] && (u == -1 || dist[j] < dist[u])) u = j;
        if (u == -1 || dist[u] == INF) break;
        vis[u] = true;

        for (int v = 1; v <= n; ++v)
            if (adj[u][v] < INF && dist[v] > dist[u] + adj[u][v]) {
                dist[v] = dist[u] + adj[u][v];
                parent[v] = u;
            }
    }

    if (dist[dest] == INF) {
        fout << "Aucun chemin entre " << start << " et " << dest << "\n";
        return;
    }

    fout << "Distance minimale = " << dist[dest] << "\n";
    vector<int> path;
    for (int v = dest; v != -1; v = parent[v]) path.push_back(v);
    reverse(path.begin(), path.end());
    fout << "Chemin le plus court : ";
    for (size_t i = 0; i < path.size(); ++i) {
        if (i) fout << " -> ";
        fout << path[i];
    }
    fout << "\n";
}


void question_5_2(ifstream &fin, ofstream &fout) {
    fout << "=== Question 5.2 : Dijkstra avec liste d'adjacence ===\n";

    int n, m, start, dest;
    fin >> n >> m >> start >> dest;

    vector<vector<pair<int,int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w; fin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> dist(n + 1, INF), parent(n + 1, -1), vis(n + 1, 0);
    dist[start] = 0;

    for (int i = 1; i <= n; ++i) {
        int u = -1;
        for (int j = 1; j <= n; ++j)
            if (!vis[j] && (u == -1 || dist[j] < dist[u])) u = j;
        if (u == -1 || dist[u] == INF) break;
        vis[u] = 1;

        for (auto [v, w] : adj[u])
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
    }

    if (dist[dest] == INF) {
        fout << "Aucun chemin entre " << start << " et " << dest << "\n";
        return;
    }

    fout << "Distance minimale = " << dist[dest] << "\n";
    vector<int> path;
    for (int v = dest; v != -1; v = parent[v]) path.push_back(v);
    reverse(path.begin(), path.end());
    fout << "Chemin le plus court : ";
    for (size_t i = 0; i < path.size(); ++i) {
        if (i) fout << " -> ";
        fout << path[i];
    }
    fout << "\n";
}



int main() {
    ifstream fin("INPDIJGRAPH.TXT");
    ofstream fout("OUTDIJGRAPH.TXT");

    if (!fin) {
        cerr << "Impossible d'ouvrir le fichier d'entrée.\n";
        return 1;
    }


    question_5_2(fin, fout);

    return 0;
}
