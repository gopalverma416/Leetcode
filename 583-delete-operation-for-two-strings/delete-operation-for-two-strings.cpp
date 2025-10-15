class Solution {
    vector<vector<int>> dp;

    int lcs(int i, int j, string &word1, string &word2) {
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j]) 
            return dp[i][j] = 1 + lcs(i-1, j-1, word1, word2);
        else 
            return dp[i][j] = max(lcs(i-1, j, word1, word2), lcs(i, j-1, word1, word2));
    }

public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        dp.assign(n, vector<int>(m, -1));

        int lcsLen = lcs(n-1, m-1, word1, word2);
        return (n - lcsLen) + (m - lcsLen);
    }
};
