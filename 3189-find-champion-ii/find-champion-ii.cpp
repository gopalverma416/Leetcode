class Solution {
private:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& indegree, vector<bool>& vis) {
        vis[node] = true;
        for (auto& it : adj[node]) {
            indegree[it]++;
            if (!vis[it]) {
                dfs(it, adj, indegree, vis);
            }
        }
    }

public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }

        vector<int> indegree(n, 0);
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, adj, indegree, vis);
            }
        }

        bool first = false;
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0 && !first) {
                first = true;
                ans = i;
            } else if (indegree[i] == 0 && first) {
                return -1; 
            }
        }
        return ans;
    }
};
