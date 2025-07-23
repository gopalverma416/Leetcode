class Solution {
    int score = 0;
    int maxi = -1;

    void dfs(int node, vector<int>& edges, vector<bool>& vis, vector<int>& dist, int depth) {
        vis[node] = true;
        dist[node] = depth;

        int next = edges[node];
        if (next != -1) {
            if (!vis[next]) {
                dfs(next, edges, vis, dist, depth + 1);
            } else if (dist[next] != -1) {
                // Found a cycle
                maxi = max(maxi, depth - dist[next] + 1);
            }
        }

       
        dist[node] = -1;
    }

public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> vis(n, false);
        vector<int> dist(n, -1);

        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                dfs(i, edges, vis, dist, 0);
            }
        }

        return maxi;
    }
};
