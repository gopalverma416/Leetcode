class Solution {
    private:
     vector<vector<int>>dp;
    int solve(int i,int j,string& s,string& p){
       if(j<0){
        return 1;
       }
       if(i<0){
        return 0;
       }
       if(dp[i][j]!=-1){
        return dp[i][j];
       }
       int take=0;
       if(s[i]==p[j]){
        take= solve(i-1,j-1,s,p);
       }
       int drop=solve(i-1,j,s,p);
       return dp[i][j]= take+drop;
    }
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
       dp.resize(n,vector<int>(m,-1));
       return solve(n-1,m-1,s,t);
    }
};