class Solution {
private:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, int& nodes, int& edges) {
        vis[node] = 1;
        nodes++;
        edges += adj[node].size();  // count all incident edges
        for (auto& neig : adj[node]) {
            if (vis[neig] == -1) {
                dfs(neig, adj, vis, nodes, edges);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        // build graph
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, -1);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] == -1) {
                int nodes = 0, edgesCount = 0;
                dfs(i, adj, vis, nodes, edgesCount);

               
                edgesCount /= 2;

               
                if (edgesCount == (nodes * (nodes - 1)) / 2) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
