class Solution {
private:
    bool isPalindromeHelper(const string& s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }

public:
    bool isPalindrome(string s) {
        string result;

        for (char ch : s) {
            if (isalnum(ch)) {
                result += tolower(ch); 
            }
        }

        return isPalindromeHelper(result);
    }
};
