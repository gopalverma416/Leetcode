class Solution {
    private:
    int solve(int idx,vector<int>& nums,int right,vector<int>& dp){
       
        if(idx==right){
            return nums[idx];
        }
        if(idx>=(right+1)){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int take=nums[idx]+solve(idx+2,nums,right,dp);
        int drop=solve(idx+1,nums,right,dp);
        return dp[idx]= max(take,drop);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
         vector<int>dp(n,-1);
        int take1= solve(0,nums,n-2,dp);
        dp.assign(n, -1);
        int take2=solve(1,nums,n-1,dp);
        return max(take1,take2);
    }
};