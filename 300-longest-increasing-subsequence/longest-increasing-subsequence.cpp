class Solution {
    private:
    vector<vector<int>>dp;
    int solve(int idx,vector<int>& nums,int prev){
        int n=nums.size();
         if(idx==n){
            return 0;
         }
        if(dp[idx][prev+1]!=-1){
            return dp[idx][prev+1];
        }
       int take=INT_MIN;
       if(prev==-1||nums[prev]<nums[idx]){
        take=1+solve(idx+1,nums,idx);
       }
       int nonTake=solve(idx+1,nums,prev);
       return dp[idx][prev+1]=max(take,nonTake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        int prev=-1;
        dp.resize(n+1,vector<int>(n+1,-1));
        return solve(0,nums,prev);
    }
};