class Solution {
    int n;
    vector<vector<vector<int>>> dp;

    int dfs(int idx, vector<int>& prices, int k, int holding, int cnt) {
        if (idx == n || cnt == k) return 0;

        if (dp[idx][holding][cnt] != -1) return dp[idx][holding][cnt];

        int take = 0, drop = 0;

     
        if (holding == 0) {
            take = dfs(idx + 1, prices, k, 1, cnt) - prices[idx];
        }
       
        if (holding == 1) {
            drop = dfs(idx + 1, prices, k, 0, cnt + 1) + prices[idx];
        }

       
        int normal = dfs(idx + 1, prices, k, holding, cnt);

        return dp[idx][holding][cnt] = max({take, drop, normal});
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        dp.assign(n + 1, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return dfs(0, prices, k, 0, 0);
    }
};
