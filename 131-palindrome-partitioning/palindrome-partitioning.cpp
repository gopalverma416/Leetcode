class Solution {
private:
    vector<vector<string>> result;
    bool palindrome(string s){
        int left=0;
        int n=s.size();
        int right=n-1;
        while(left<=right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void solve(int idx, string s, vector<string>& ans) {
        int n = s.size();
        if (idx == n) {
            result.push_back(ans);
        }
    
        for (int len = 1; len <= n - idx; len++) {
            string copy = s.substr(idx, len);
            if (palindrome(copy)) {
                ans.push_back(copy);
                solve(idx + len, s, ans);
                ans.pop_back();
            }
        }

    }
    public:
        vector<vector<string>> partition(string s) {
            int n = s.size();
            vector<string> ans;
            solve(0, s, ans);
            return result;
        }
    };