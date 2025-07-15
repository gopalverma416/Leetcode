class Solution {
public:
    bool isValid(string word) {
        int n = word.size();
        if (n < 3) return false;

        bool hasConsonant = false;
        bool hasVowel = false;

        for (char ch : word) {
            if (isalpha(ch)) {
                char lower = tolower(ch); 
                if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                    hasVowel = true;
                } else {
                    hasConsonant = true;
                }
            } else if (isdigit(ch)) {
                continue; 
            } else {
                return false; 
            }
        }

        return hasConsonant && hasVowel;
    }
};
