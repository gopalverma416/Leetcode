class Solution {
private:
    int solve(int left, int right, vector<int>& nums, vector<vector<int>> &dp) {
        if (left + 1 == right) return 0;

        if (dp[left][right] != -1) return dp[left][right];

        int maxCoins = 0;
        for (int i = left + 1; i < right; i++) {
            int coins = nums[i] * nums[left] * nums[right];
            coins += solve(left, i, nums, dp);
            coins += solve(i, right, nums, dp);
            maxCoins = max(maxCoins, coins);
        }

        return dp[left][right] = maxCoins;
    }

public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, n - 1, nums, dp);
    }
};
