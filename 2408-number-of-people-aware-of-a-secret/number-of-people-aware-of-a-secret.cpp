class Solution {
    private:

    int MOD=1e9+7;
    int solve(int day,int delay,int forget,vector<int>& dp){
        if(day==1){
            return 1;
        }
        int cnt=0;
        if(dp[day]!=-1){
            return dp[day];
        }
        for(int prev=day-forget+1;prev<=day-delay;prev++){
            if(prev<0){
                continue;
            }
            cnt=(cnt+solve(prev,delay,forget,dp))%MOD;
        }
        return dp[day]= cnt;
    }
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        //n-forget+1 se n-delay  peole will know the secret only 
        int result=0;
        vector<int>dp(n+1,-1);
       for(int d=n-forget+1;d<=n;d++){
        if(d<0){
            continue;
        }
        result=(result+solve(d,delay,forget,dp))%MOD;
       }
       return result;
    }
};