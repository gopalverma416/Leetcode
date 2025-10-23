class Solution {
public:
    void dfs(int idx, vector<vector<int>>& stones, vector<int>& vis) {
        vis[idx] = 1;
        for (int i = 0; i < stones.size(); i++) {
            if (!vis[i] && (stones[i][0] == stones[idx][0] || stones[i][1] == stones[idx][1])) {
                dfs(i, stones, vis);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> vis(n, 0);
        int components = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                components++;
                dfs(i, stones, vis);
            }
        }
        return n - components;
    }
};

