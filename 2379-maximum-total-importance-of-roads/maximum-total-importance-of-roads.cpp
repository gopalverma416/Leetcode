class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        int m = roads.size();
        vector<int> indegree(n, 0);   
        vector<vector<int>> adj(n);   
        for (int i = 0; i < m; i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }

        vector<pair<int, int>> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back({indegree[i], i});
        }

        sort(ans.begin(), ans.end());
        long long result = 0;

        for (int i = n - 1; i >= 0; i--) {
            result += 1LL * (i + 1) * ans[i].first; 
        }

        return result;
    }
};
