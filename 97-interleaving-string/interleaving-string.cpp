class Solution {
private:
    int n, m, len;
    vector<vector<int>> dp; 

    bool solve(int i, int j, string &s1, string &s2, string &s3) {
        int k = i + j;
        if (k == len) return (i == n && j == m);

        if (dp[i][j] != -1) return dp[i][j]; 

        bool ans = false;

        if (i < n && s1[i] == s3[k])
            ans = ans || solve(i + 1, j, s1, s2, s3);

        if (j < m && s2[j] == s3[k])
            ans = ans || solve(i, j + 1, s1, s2, s3);

        return dp[i][j] = ans;
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
        n = s1.size();
        m = s2.size();
        len = s3.size();

        if (n + m != len) return false;

        dp.assign(n + 1, vector<int>(m + 1, -1));
        return solve(0, 0, s1, s2, s3);
    }
};
