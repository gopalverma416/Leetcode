class Solution {
    private:
    int solve(int target,vector<int>& nums,vector<int>& dp){
        if(target==0){
            return 1;
        }
        if(target<0){
        return 0;
        }
        if(dp[target]!=-1){
            return dp[target];
        }
        int way=0;
        for(int num : nums){
          way+=solve(target-num,nums,dp);
        }
        return dp[target]= way;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>dp(target+1,-1);
        return solve(target,nums,dp);
    }
};