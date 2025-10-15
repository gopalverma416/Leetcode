class Solution {
public:
   vector<int>dp;
    int solve(int idx, string s) {
        int n=s.size();
        if(idx==n){
            return 1;
        }
        int take = 0;
        if(s[idx]=='0'){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        if (idx < n) {
            int val = s[idx] - '0';
            if (val <= 26 && val > 0) {
                take = solve(idx + 1, s);
            }
        }
        int take2 = 0;
        if (idx + 1 < n) {
            int val=(s[idx]-'0')*10+(s[idx+1]-'0');
             if (val <= 26 && val > 0) {
                take2 = solve(idx + 2, s);
            }
        }
        return dp[idx]= take+take2;
    }
    int numDecodings(string s) {
        int n=s.size();
        dp.resize(n,-1);
        return solve(0, s);
    }
};