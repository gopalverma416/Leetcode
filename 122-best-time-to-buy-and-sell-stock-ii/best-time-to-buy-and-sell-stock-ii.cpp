class Solution {
    private:
    vector<vector<int>>dp;
    int solve(int idx,vector<int>& nums,int hold){
        int n=nums.size();
        if(idx==n){
            return 0;
        }
        if(dp[idx][hold]!=-1){
            return dp[idx][hold];
        }
        
        if(hold==0){
          int take=-nums[idx]+solve(idx+1,nums,1);
          int drop=solve(idx+1,nums,hold);
          return dp[idx][hold]= max(take,drop);
        }else{
             int take=+nums[idx]+solve(idx+1,nums,0);
               int drop=solve(idx+1,nums,hold);
               return dp[idx][hold]= max(take,drop);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int hold=0;
        dp.assign(n,vector<int>(2,-1));
        return solve(0,prices,hold);
    }
};