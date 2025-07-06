 class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp; // fixed typo 'unorderd_map'
        unordered_map<string, char> rev; // for reverse mapping (one-to-one check)

        stringstream ss(s);
        string word;
        int i = 0;

        while (ss >> word) {
            if (i >= pattern.size()) return false; // more words than pattern

            char ch = pattern[i];

            if (!mp.count(ch)) {
                if (rev.count(word)) return false; // word already mapped to some other char
                mp[ch] = word;
                rev[word] = ch;
            } else {
                if (mp[ch] != word) return false;
            }

            i++;
        }

        return i == pattern.size(); // check if pattern is fully used
    }
};
