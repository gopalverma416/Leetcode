class Solution {
    private:
    int dp[50001][2];

    int solve(int idx, vector<int>& prices, int fee, bool buy) {
        if (idx == prices.size()) return 0;
        if (dp[idx][buy] != -1) return dp[idx][buy];

        int profit = 0;
        if (buy) {
          
            profit = max(-prices[idx] + solve(idx + 1, prices, fee, false),
                         solve(idx + 1, prices, fee, true));
        } else {
         
            profit = max(prices[idx] - fee + solve(idx + 1, prices, fee, true),
                         solve(idx + 1, prices, fee, false));
        }

        return dp[idx][buy] = profit;
    }

public:
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp, -1, sizeof(dp));
        return solve(0, prices, fee, true);
    }
};
