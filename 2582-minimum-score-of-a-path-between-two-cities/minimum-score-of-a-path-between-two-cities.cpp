class Solution {
private:
    void dfs(int node, vector<vector<pair<int,int>>>& adj, vector<bool>& vis, int& minEdge) {
        vis[node] = true;
        for (auto& nei : adj[node]) {
            int node2 = nei.first;
            int weight = nei.second;
            minEdge = min(minEdge, weight);
            if (!vis[node2]) {
                dfs(node2, adj, vis, minEdge);
            }
        }
    }

public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);  

        for (auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int w = road[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        int minEdge = INT_MAX;
        vector<bool> vis(n + 1, false);
        dfs(1, adj, vis, minEdge);

        return minEdge;
    }
};
