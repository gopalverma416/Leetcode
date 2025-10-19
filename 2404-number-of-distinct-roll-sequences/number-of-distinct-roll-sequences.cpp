class Solution {
    const int MOD = 1e9+7;
int dp[10005][7][7];


int solve(int pos, int n, int last, int second_last) {
    if (pos == n) return 1; 
    int &res = dp[pos][last][second_last];
    if (res != -1) return res; 
    res = 0;
    for (int d = 1; d <= 6; ++d) { 
        if (pos == 0) {
            res = (res + solve(pos+1, n, d, 0)) % MOD; 
        } else if (pos == 1) {
            if (__gcd(d, last) == 1 && d != last) 
                res = (res + solve(pos+1, n, d, last)) % MOD;
        } else {
            if (__gcd(d, last) == 1 && d != last && d != second_last) 
                res = (res + solve(pos+1, n, d, last)) % MOD;
        }
    }
    return res;
}

public:
   int distinctSequences(int n) {
    memset(dp, -1, sizeof(dp));
    return solve(0, n, 0, 0);
}

};