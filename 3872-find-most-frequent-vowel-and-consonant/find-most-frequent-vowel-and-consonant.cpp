class Solution {
private:
    bool isValid(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true;
        }
        return false;
    }

public:
    int maxFreqSum(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        int max_v = 0;
        int max_c = 0;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (isValid(ch)) {
                mp[ch]++;
                max_v=max(max_v,mp[ch]);
            }else{
                mp[ch]++;
                max_c=max(max_c,mp[ch]);
            }
        }
        return max_v+max_c;
    }
};