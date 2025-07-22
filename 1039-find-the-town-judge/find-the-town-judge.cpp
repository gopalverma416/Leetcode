class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < trust.size(); i++) {
            int u = trust[i][0];
            int v = trust[i][1];
            adj[v - 1].push_back(u - 1); 
        }

        vector<int> post(n, 0);
        vector<int> indegree(n, 0);
        
        for (int i = 0; i < n; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
                post[i]++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0 && post[i] == n - 1) {
                return i + 1; 
            }
        }

        return -1; 
    }
};
