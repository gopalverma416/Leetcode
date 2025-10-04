class Solution {
private:
    int solve(int idx, vector<int>& nums,vector<int>& dp) {
        int n = nums.size();
        if (idx == n - 1) {
            return nums[idx];
        }
        if(idx>=n){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
         int take = 0;
        if (idx < n) {
            take = nums[idx] + solve(idx + 2, nums, dp);
        }
        int drop = solve(idx + 1, nums, dp);
       
        return dp[idx]= max(take, drop);
    }

public:
    int rob(vector<int>& nums) {
        int idx = 0;
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(0, nums,dp);
    }
};