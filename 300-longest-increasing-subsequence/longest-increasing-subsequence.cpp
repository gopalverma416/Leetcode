class Solution {
    private:
     vector<vector<int>>dp;
    int solve(int idx,vector<int>& nums,int last){
        int n=nums.size();
        if(idx==n){
            return 0;
        }
        int take=INT_MIN;
        if(dp[idx][last+1]!=-1){
            return dp[idx][last+1];
        }
        if(last==-1 || nums[last]<nums[idx]){
          take=1+solve(idx+1,nums,idx);
        }
        int drop=solve(idx+1,nums,last);
        return dp[idx][last+1]= max(take,drop);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int last=-1;
        dp.resize(n,vector<int>(n+1,-1));
       return  solve(0,nums,last);
    }
};