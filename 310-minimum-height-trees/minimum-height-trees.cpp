class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }
        vector<vector<int>> adj(n);
        int sz = edges.size();
        vector<int> indegree(n, 0);
        for (int i = 0; i < sz; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }
        queue<int> pq;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 1) {
                pq.push(i);
            }
        }
        int total = n;
        while (total > 2) {
            int sz1 = pq.size();
            total -= sz1;
            for (int i = 0; i < sz1; i++) {
                int node = pq.front();
                pq.pop();
                for (auto neigh : adj[node]) {
                    indegree[neigh]--;
                    if (indegree[neigh] == 1) {
                        pq.push(neigh);
                    }
                }
            }
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.front());
            pq.pop();
        }
        return ans;
    }
};