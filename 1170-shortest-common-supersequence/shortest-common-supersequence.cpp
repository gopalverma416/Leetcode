class Solution {
public:
    string shortestCommonSupersequence(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == p[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        int i = n;
        int j = m;
        string result = "";
        while (i > 0 && j > 0) {
            if (s[i - 1] == p[j - 1]) {
                result += s[i - 1];
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                result += s[i - 1];
                i--;
            } else {
                result += p[j - 1];
                j--;
            }
        }
         while(i>0){
            result+=s[i-1];
            i--;
        }
        while(j>0){
            result+=p[j-1];
            j--;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};