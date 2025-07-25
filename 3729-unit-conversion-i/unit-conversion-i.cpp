class Solution {
private:
    vector<int> res;
    const int MOD = 1e9 + 7;

    void dfs(int node, vector<vector<pair<int, int>>>& adj, vector<bool>& vis, long long score) {
        vis[node] = true;
        for (auto& it : adj[node]) {
            int node2 = it.first;
            int wt = it.second;
            if (!vis[node2]) {
                long long newScore = (score * wt) % MOD;
                res[node2] = newScore;
                dfs(node2, adj, vis, newScore);
            }
        }
    }

public:
    vector<int> baseUnitConversions(vector<vector<int>>& nums) {
        int n = nums.size();
        int maxNode = 0;
        for (auto& num : nums) {
            maxNode = max({maxNode, num[0], num[1]});
        }

        vector<vector<pair<int, int>>> adj(maxNode + 1);
        for (int i = 0; i < n; i++) {
            int u = nums[i][0];
            int v = nums[i][1];
            int wt = nums[i][2];
            adj[u].push_back({v, wt});
        }

        res.resize(maxNode + 1, -1);
        vector<bool> vis(maxNode + 1, false);
        res[0] = 1;

        dfs(0, adj, vis, 1);

        return res;
    }
};
