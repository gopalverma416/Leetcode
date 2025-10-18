class Solution {
private:
    vector<vector<int>> dp;

    int solve(int idx, vector<int>& prices, int fee, int pur) {
        int n = prices.size();
        if (idx == n) return 0;  

        if (dp[idx][pur] != -1) return dp[idx][pur];

        int take = 0;
        if (pur) {
          
            take = -prices[idx] + solve(idx + 1, prices, fee, 0);
        } else {
           
            take = prices[idx] - fee + solve(idx + 1, prices, fee, 1);
        }

        int skip = solve(idx + 1, prices, fee, pur);
        return dp[idx][pur] = max(take, skip);
    }

public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        dp.assign(n, vector<int>(2, -1));
        return solve(0, prices, fee, 1); 
    }
};
