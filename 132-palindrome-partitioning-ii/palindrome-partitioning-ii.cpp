class Solution {
private:
    bool palindrome(int i, int j, string &s) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int solve(int idx, string &s, vector<int> &dp) {
        int n = s.size();
        if (idx == n) return -1;
        if (dp[idx] != -1) return dp[idx];

        int mini = INT_MAX;
        for (int j = idx; j < n; j++) {
            if (palindrome(idx, j, s)) {
                int cost = 1 + solve(j + 1, s, dp);
                mini = min(mini, cost);
            }
        }
        return dp[idx] = mini;
    }

public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return solve(0, s, dp);
    }
};
