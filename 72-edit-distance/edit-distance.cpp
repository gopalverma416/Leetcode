class Solution {
    private:
    vector<vector<int>>dp;
    int solve(int i,int j,string& s,string& p){
       if(i<0){
        return j+1;
       }
       if(j<0){
        return i+1;
       }
       if(dp[i][j]!=-1){
        return dp[i][j];
       }
       if(s[i]==p[j]){
        return dp[i][j]= solve(i-1,j-1,s,p);
       }
       int insert=1+solve(i,j-1,s,p);
       int delete1=1+solve(i-1,j,s,p);
       int repalace=1+solve(i-1,j-1,s,p);
       return dp[i][j]= min({insert,delete1,repalace});
    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        dp.resize(n,vector<int>(m,-1));
        return solve(n-1,m-1,word1,word2);
    }
};