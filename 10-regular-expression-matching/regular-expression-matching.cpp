class Solution {
private:
    bool solve(int i, int j, string &s, string &p) {
        if(j < 0) return i < 0;

        if(i < 0) {
          
            if(p[j] == '*') {
                return solve(i, j - 2, s, p);
            }
            return false;
        }

        if(p[j] == '*') {
          
            if(s[i] == p[j - 1] || p[j - 1] == '.') {
                return solve(i - 1, j, s, p) || solve(i, j - 2, s, p);
            } else {
                return solve(i, j - 2, s, p); 
            }
        } else if(p[j] == '.' || s[i] == p[j]) {
            return solve(i - 1, j - 1, s, p);
        } else {
            return false;
        }
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        return solve(n - 1, m - 1, s, p);
    }
};
 
