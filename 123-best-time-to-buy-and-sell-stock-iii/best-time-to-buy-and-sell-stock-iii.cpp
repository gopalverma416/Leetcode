class Solution {
private:
    int n;
    vector<vector<vector<int>>> dp;
    
    int solve(int idx, int trans, int holding, vector<int>& prices) {
        if (idx == n || trans == 0) return 0; 
        if (dp[idx][trans][holding] != -1) return dp[idx][trans][holding];
        
        int skip = solve(idx + 1, trans, holding, prices); // do nothing
        
        if (holding) {
           
            int sell = prices[idx] + solve(idx + 1, trans - 1, 0, prices);
            return dp[idx][trans][holding] = max(skip, sell);
        } else {
            
            int buy = -prices[idx] + solve(idx + 1, trans, 1, prices);
            return dp[idx][trans][holding] = max(skip, buy);
        }
    }

public:
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.assign(n, vector<vector<int>>(3, vector<int>(2, -1)));
        return solve(0, 2, 0, prices); // start at day 0, 2 transactions, not holding
    }
};
