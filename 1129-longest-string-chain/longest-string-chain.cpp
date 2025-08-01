class Solution {
private:
    int solve(unordered_map<string, bool>& mp, string s, unordered_map<string,int>& dp) {
        int n = s.size();
        int maxi = 1; 
       if(dp.find(s)!=dp.end()){
        return dp[s];
       }
        for (int i = 0; i < n; i++) {
            string copy = s;
            copy.erase(i, 1);
            if (mp.find(copy) != mp.end()) {
                int take = 1 + solve(mp, copy,dp);
                maxi = max(maxi, take);
            }
        }
        return dp[s]=maxi;
    }

public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, bool> mp;
        for (int i = 0; i < words.size(); i++) {
            mp[words[i]] = true;
        }
        unordered_map<string,int>dp;
        int ans = 0;
        for (int i = 0; i < words.size(); i++) {
            ans = max(ans, solve(mp, words[i],dp));
        }
        return ans;
    }
};
