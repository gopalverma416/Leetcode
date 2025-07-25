class Solution {
private:
    void dfs(int node, vector<vector<int>>& adj, vector<set<int>>& res, vector<bool>& vis) {
        vis[node] = true;
        for (auto& it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, res, vis);
            }
            res[node].insert(it);
            res[node].insert(res[it].begin(), res[it].end()); 
        }
    }

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<set<int>> resSet(n);
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[v].push_back(u);
        }
         vector<bool> vis(n, false);
        for (int i = 0; i < n; ++i) {
           
            dfs(i, adj, resSet, vis);
        }

        vector<vector<int>> res(n);
        for (int i = 0; i < n; ++i) {
            res[i] = vector<int>(resSet[i].begin(), resSet[i].end());
            sort(res[i].begin(), res[i].end()); 
        }
        return res;
    }
};
