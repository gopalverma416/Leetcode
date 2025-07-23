class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 2); 

        for (int i = 0; i < n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u); 
        }

        for (int i = 1; i <= n + 1; i++) { 
            if (adj[i].size() == n) {
                return i; 
            }
        }

        return -1;
    }
};
