class Solution {
public:
    int longestSubstring(string s, int k) {
        int maxLen = 0;
        int n = s.size();

        for (int curr_unique = 1; curr_unique <= 26; ++curr_unique) {
            vector<int> freq(26, 0);
            int left = 0, right = 0;
            int unique = 0;             
            int count_at_least_k = 0;   // chars with freq >= k

            while (right < n) {
                if (freq[s[right] - 'a'] == 0) unique++;
                freq[s[right] - 'a']++;
                if (freq[s[right] - 'a'] == k) count_at_least_k++;
                right++;

                while (unique > curr_unique) {
                    if (freq[s[left] - 'a'] == k) count_at_least_k--;
                    freq[s[left] - 'a']--;
                    if (freq[s[left] - 'a'] == 0) unique--;
                    left++;
                }

                if (unique == count_at_least_k)
                    maxLen = max(maxLen, right - left);
            }
        }

        return maxLen;
    }
};
