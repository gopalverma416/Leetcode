class Solution {
    private:
    vector<vector<int>>dp;
     int solve(int i,int j,string& s,string& p){
        if(i<0 && j<0){
            return true;
        }
        if(i>=0 && j<0){
            return false;
        }
        if(i<0){
            for(int k=0;k<=j;k++){
                if(p[k]!='*'){
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j]= solve(i-1,j-1,s,p);
        }
        if(p[j]=='*'){
            return dp[i][j]= solve(i,j-1,s,p)|| solve(i-1,j,s,p);
        }
        return dp[i][j]=false;
     }
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        dp.resize(n,vector<int>(m,-1));
        return  solve(n-1,m-1,s,p);
    }
};