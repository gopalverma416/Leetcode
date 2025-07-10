class Solution {
private:
    unordered_set<string> set;
    vector<int> dp; 
    bool solve(int idx, string &s) {
        if (idx == s.size()) return true;
        if (dp[idx] != -1) return dp[idx];

        for (int len = 1; len <= s.size() - idx; len++) {
            string sub = s.substr(idx, len);
            if (set.find(sub) != set.end()) {
                if (solve(idx + len, s)) {
                    return dp[idx] = 1;
                }
            }
        }

        return dp[idx] = 0;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for (string &word : wordDict) {
            set.insert(word);
        }
        dp.resize(s.size() + 1, -1);  
        return solve(0, s);
    }
};
