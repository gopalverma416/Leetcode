class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n = s.size();
        int start = 0, end = n - 1;
        int cnt = 0;

        while (start < end) { // ✅ condition changed: no need for <=
            if (s[start] == s[end]) {
                start++;
                end--;
                continue;
            }

            int left = end;
            // ✅ find matching character for s[start] from the right side
            while (left > start && s[left] != s[start]) {
                left--;
            }

            if (left == start) {
                // ✅ case: s[start] has no matching pair, it must go to the middle
                swap(s[start], s[start + 1]);
                cnt++;
            } else {
               
                while (left < end) {
                    swap(s[left], s[left + 1]);
                    cnt++;
                    left++;
                }
                start++;
                end--;
            }
        }

        return cnt;
    }
};
