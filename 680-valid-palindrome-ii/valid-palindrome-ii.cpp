class Solution {
private:
    bool isPalindrome(int i, int j, string& s, bool check) {
        if (i >= j) return true;

        if (s[i] == s[j]) {
            return isPalindrome(i + 1, j - 1, s, check);
        } else {
            if (!check) {
                return isPalindrome(i + 1, j, s, true) || isPalindrome(i, j - 1, s, true);
            } else {
                return false;
            }
        }
    }

public:
    bool validPalindrome(string s) {
        return isPalindrome(0, s.size() - 1, s, false);
    }
};
