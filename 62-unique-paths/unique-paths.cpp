class Solution {
    private:
    //  vector<vector<int>>dp;
    // int dfs(int i,int j,int m,int n){
    //    if(i==m-1 && j==n-1){
    //     return 1;
    //    }
    //     if(i<0 || j<0 || i>=m || j>=n){
    //         return 0;
    //     }
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
    //     int right=dfs(i,j+1,m,n);
    //     int down=dfs(i+1,j,m,n);
    //     return dp[i][j]=right+down;
    // }
    vector<vector<int>>dp;
public:
    int uniquePaths(int m, int n) {
        dp.resize(m+1,vector<int>(n+1,0));
        for(int i = 0; i < m; i++) dp[i][0] = 1;
        for(int j = 0; j < n; j++) dp[0][j] = 1;

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]+=(dp[i-1][j]+dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
};