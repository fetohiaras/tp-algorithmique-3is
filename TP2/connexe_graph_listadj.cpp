#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<char> vis;
vector<int> component;

void dfs(int u) {
    vis[u] = 1;
    component.push_back(u);
    for(int v : adj[u]) {
        if (!vis[v]) dfs(v);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n >> m)) return 0;
    adj.assign(n+1, {});
    for(int i = 0; i < m; ++i){
        int u,v; cin >> u >> v;
        if (u>=1 && u<=n && v>=1 && v<=n) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    vis.assign(n+1, 0);
    vector<vector<int>> components;

    for(int v = 1; v <= n; ++v){
        if (!vis[v]) {
            component.clear();
            dfs(v);
            sort(component.begin(), component.end());
            components.push_back(component);
        }
    }

    sort(components.begin(), components.end(), [](const vector<int>& a, const vector<int>& b){
        return a.front() < b.front();
    });

    cout << components.size() << "\n";
    for(size_t i = 0; i < components.size(); ++i){
        cout << "composante connexe " << (i+1) << "\n\n";
        for(size_t j = 0; j < components[i].size(); ++j){
            if (j) cout << ' ';
            cout << components[i][j];
        }
        cout << "\n\n";
    }

    return 0;
}
