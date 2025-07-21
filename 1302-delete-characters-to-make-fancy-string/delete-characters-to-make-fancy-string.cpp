class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        for (int i = n - 2; i >= 1; i--) {
            if (s[i - 1] == s[i] && s[i] == s[i + 1]) {
                s.erase(i, 1);
            }
        }
        return s;
    }
};
