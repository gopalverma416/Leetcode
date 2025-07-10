class Solution {
private:
    unordered_set<string> dict;

    void solve(int idx, string& s, string str, vector<string>& result) {
        int n = s.size();
        if (idx == n) {
            result.push_back(str);
            return;
        }

        for (int len = 1; idx + len <= n; len++) {
            string sub = s.substr(idx, len);
            if (dict.count(sub)) {
                string current;
                if (str.empty()) {
                    current = sub;
                } else {
                    current = str + " " + sub;
                }
                solve(idx + len, s, current, result);
            }
        }
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dict.clear();
        for (auto& word : wordDict) {
            dict.insert(word);
        }
        vector<string> result;
        solve(0, s, "", result);
        return result;
    }
};
