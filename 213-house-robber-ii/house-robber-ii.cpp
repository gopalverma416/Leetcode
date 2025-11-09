class Solution {
private:
    int solve(int start, int end, vector<int>& nums, vector<int>& dp) {
        if (start > end) return 0;
        if (dp[start] != -1) return dp[start];

       
        int take = nums[start] + solve(start + 2, end, nums, dp);
       
        int skip = solve(start + 1, end, nums, dp);

        return dp[start] = max(take, skip);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        vector<int> dp1(n, -1), dp2(n, -1);
        int first = solve(0, n - 2, nums, dp1); 
        int second = solve(1, n - 1, nums, dp2); 

        return max(first, second);
    }
};
