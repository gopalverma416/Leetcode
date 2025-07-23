class Solution {
private:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, int& count) {
        vis[node] = true;
        count++;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis, count);
            }
        }
    }

public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);

      
        for (int i = 0; i < n; i++) {
            long long xi = bombs[i][0];
            long long yi = bombs[i][1];
            long long ri = bombs[i][2];

            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                long long xj = bombs[j][0];
                long long yj = bombs[j][1];

                long long dx = xi - xj;
                long long dy = yi - yj;
                long long distSq = dx * dx + dy * dy;

                if (distSq <= ri * ri) {
                    adj[i].push_back(j); 
                }
            }
        }

        int maxi = 0;

       
        for (int i = 0; i < n; i++) {
            vector<bool> vis(n, false);
            int count = 0;
            dfs(i, adj, vis, count);
            maxi = max(maxi, count);
        }

        return maxi;
    }
};
