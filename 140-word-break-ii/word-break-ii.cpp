class Solution {
public:
    set<string> st;
    vector<string> result;
    void solve(int idx, string& s, string& ans) {
        int n = s.size();
        if (idx==n){
            result.push_back(ans);
        }
            for (int len = 1; len < n-idx+1; len++) {
                string news = s.substr(idx, len);
                if (st.find(news) != st.end()) {
                    string prev = ans;
                    ans += news;
                    if(idx+len<n){
                    ans+=' ';
                    }
                   
                    solve(idx + len, s, ans);
                    ans = prev;
                }
            }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (auto qw : wordDict) {
            st.insert(qw);
        }
        string ans="";
        solve(0,s,ans);
        return result;
    }
};