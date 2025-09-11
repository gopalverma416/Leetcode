class Solution {
private:
    void solve(int idx, string& ans) {
        if (idx == 1) {
            ans = "1";
            return;
        }
        solve(idx - 1, ans);  // get previous sequence
        int n = ans.size();
        string res = "";
        for (int i = 0; i < n;) {
            char prev = ans[i];
            int j = i;
            while (j < n && ans[j] == prev) {
                j++;
            }
            int cnt = j - i;      
            res += to_string(cnt); 
            res += prev;          
            i = j;              
        }
        ans = res;
    }

public:
    string countAndSay(int n) {
        string ans = "";
        solve(n, ans);
        return ans;
    }
};
