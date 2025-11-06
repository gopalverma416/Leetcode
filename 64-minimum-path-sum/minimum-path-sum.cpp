class Solution {
private:
   vector<vector<int>>dp;
    int dfs(int i, int j, int n, int m, vector<vector<int>>& grid) {
        if (i < 0 || j < 0) {
            return 0;
        }
        if (i >= n || j >= m) {
            return 1e9;
        }

        if (i == n - 1 && j == m - 1)
            return grid[i][j];

        if(dp[i][j]!=-1){
            return dp[i][j];
        }    
        
        int right = grid[i][j] + dfs(i, j + 1, n, m, grid);
        int down = grid[i][j] + dfs(i + 1, j, n, m, grid);

        return dp[i][j]= min({right, down});
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        dp.resize(n+1,vector<int>(m+1,-1));
        return dfs(0, 0, n, m, grid);
    }
};