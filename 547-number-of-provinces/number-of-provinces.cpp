class Solution {
private:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;
        for (auto neig : adj[node]) {
            if (vis[neig] == 1) {
                continue;
            }
            dfs(neig, adj, vis);
        }
    }

public:
    int findCircleNum(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                int u = i;
                int v = j;
             
                if (v == u) {
                    continue;
                }
                if(nums[i][j]==1){
                  adj[u].push_back(v);
                }
            }
        }
        int cnt = 0;
        vector<int> vis(n + 1, -1);
        for (int i = 0; i < n; i++) {
            if (vis[i] == -1) {
                dfs(i, adj, vis);
                cnt++;
            }
        }
        return cnt;
    }
};