class Solution {
private:
    int MOD = 1e9 + 7;
    vector<vector<int>> dp;

    int solve(int idx, int n, int k, int target) {
        if (idx == n) {
            return target == 0; 
        }
        if (target < 0) return 0;

        if (dp[idx][target] != -1) 
            return dp[idx][target];

        long long total = 0;
        for (int i = 1; i <= k; i++) {
            if (target - i >= 0)
                total = (total + solve(idx + 1, n, k, target - i)) % MOD;
        }

        return dp[idx][target] = total; 
    }

public:
    int numRollsToTarget(int n, int k, int target) {
        dp.resize(n + 1, vector<int>(target + 1, -1)); 
        return solve(0, n, k, target); 
    }
};
