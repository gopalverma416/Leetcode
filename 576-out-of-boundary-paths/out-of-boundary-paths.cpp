class Solution {
private:
    int mod = 1e9 + 7;

    int solve(int rw, int cl, int m, int n, int maxMove, vector<vector<vector<int>>>& dp) {
        if (rw < 0 || rw >= m || cl < 0 || cl >= n) return 1; 
        if (maxMove == 0) return 0; 

        if (dp[rw][cl][maxMove] != -1) return dp[rw][cl][maxMove];

        int ways = 0;
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nrw = rw + dr[i];
            int ncl = cl + dc[i];
            ways = (ways + solve(nrw, ncl, m, n, maxMove - 1, dp)) % mod;
        }

        return dp[rw][cl][maxMove] = ways;
    }

public:
    int findPaths(int m, int n, int maxMove, int startRow, int startCol) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return solve(startRow, startCol, m, n, maxMove, dp);
    }
};
