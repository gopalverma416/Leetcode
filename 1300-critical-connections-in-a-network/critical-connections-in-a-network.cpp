#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (auto& c : connections) {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }

        vector<int> disc(n, -1), low(n, -1);
        vector<vector<int>> bridges;
        int time = 0;

        function<void(int, int)> dfs = [&](int u, int parent) {
            disc[u] = low[u] = time++;
            for (int v : adj[u]) {
                if (v == parent) continue; 
                if (disc[v] == -1) {
                    dfs(v, u);
                    low[u] = min(low[u], low[v]);
                    if (low[v] > disc[u]) {
                        bridges.push_back({u, v});
                    }
                } else {
                    low[u] = min(low[u], disc[v]); 
                }
            }
        };

        dfs(0, -1);
        return bridges;
    }
};


