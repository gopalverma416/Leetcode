class Solution {
    private:
    vector<vector<int>>dp;
    int solve(int idx,vector<int>& prices,int fee,int hold){
        int n=prices.size();
        if(idx==n){
            return 0;
        }
        if(dp[idx][hold]!=-1){
            return dp[idx][hold];
        }
        int skip=solve(idx+1,prices,fee,hold);
         if(hold==1){
            int take=prices[idx]-fee+solve(idx+1,prices,fee,0);
            return dp[idx][hold]= max(take,skip);
         }else{
            int take=-prices[idx]+solve(idx+1,prices,fee,1);
            return dp[idx][hold]= max(take,skip);
         }

    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        int hold=0;
        dp.resize(n+1,vector<int>(3,-1));
        return solve(0,prices,fee,hold);
    }
};