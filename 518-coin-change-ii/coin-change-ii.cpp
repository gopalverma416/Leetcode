class Solution {
    private:
    vector<vector<int>>dp;
    int solve(int idx,int amount,vector<int>& coins){
        int n=coins.size();
        if(amount==0){
            return 1;
        }
        if(amount<0){
            return 0;
        }
        if(idx==n){
            if(amount==0){
                return 1;
            }else{
                return 0;
            }
            
        }
        if(dp[idx][amount]!=-1){
            return dp[idx][amount];
        }
        int take=solve(idx,amount-coins[idx],coins);
        int drop=solve(idx+1,amount,coins);
        return dp[idx][amount]= take+drop;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        dp.resize(n,vector<int>(amount+1,-1));
        sort(coins.begin(),coins.end());
       return solve(0,amount,coins);
    }
};