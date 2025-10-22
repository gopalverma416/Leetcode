class Solution {
    private:
     vector<vector<int>>dp;
    int solve(int idx1,int idx2,string word1,string word2){
        int mini=0;
         if(idx1<0){
            return idx2+1;
         }
         if(idx2<0){
            return idx1+1;
         }
         if(dp[idx1][idx2]!=-1){
            return dp[idx1][idx2];
         }
        if(word1[idx1]==word2[idx2]){
           return dp[idx1][idx2]= solve(idx1-1,idx2-1,word1,word2);
        }else{
            int insert=1+solve(idx1,idx2-1,word1,word2);
            int delet=1+solve(idx1-1,idx2,word1,word2);
            int replace=1+solve(idx1-1,idx2-1,word1,word2);
            mini=min({insert,delet,replace});
        }
       return dp[idx1][idx2]= mini;

    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        dp.resize(n,vector<int>(m,-1));
        return solve(n-1,m-1,word1,word2);
    }
};