class Solution {
    private:
    int solve(int idx,vector<int>& dp){
        if(idx==0 || idx==1){
            return idx;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
      int take=solve(idx-1,dp);
      int take2=solve(idx-2,dp);
      return dp[idx]=take+take2;
    }
public:
    int fib(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};