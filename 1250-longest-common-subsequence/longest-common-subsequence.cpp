class Solution {
private:
    vector<vector<int>> dp;
    
    int solve(int i, int j, string &text1, string &text2) {
        if (i == 0 || j == 0) return 0; // ✅ clean base case
        
        if (dp[i][j] != -1) return dp[i][j];
        
        if (text1[i - 1] == text2[j - 1]) {
            return dp[i][j] = 1 + solve(i - 1, j - 1, text1, text2);
        } else {
            return dp[i][j] = max(solve(i - 1, j, text1, text2),
                                  solve(i, j - 1, text1, text2));
        }
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        dp.assign(n + 1, vector<int>(m + 1, -1));  // ✅ safer dimensions
        return solve(n, m, text1, text2);
    }
};
