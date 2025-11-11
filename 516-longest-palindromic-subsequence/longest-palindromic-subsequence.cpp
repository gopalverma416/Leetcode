class Solution {
private:
    vector<vector<int>> dp;
    int solve(int i, int j, string& s) {
        if (i > j) {
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if (s[i] == s[j]) {
            if (i == j) {
                return 1 + solve(i + 1, j - 1, s);
            } else {
                return 2 + solve(i + 1, j - 1, s);
            }

        } else {
            int take1 = solve(i + 1, j, s);
            int take2 = solve(i, j - 1, s);
            return dp[i][j]= max(take1, take2);
        }
    }

public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        dp.resize(n,vector<int>(n,-1));
        return solve(0, n - 1, s);
    }
};