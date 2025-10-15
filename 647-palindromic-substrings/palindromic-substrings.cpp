#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
    int solve(const string& s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
        return count;
    }

public:
    int countSubstrings(string s) {
        if (s.empty()) return 0;

        int n = s.length();
        int total = 0;

        for (int i = 0; i < n; i++) {
            total += solve(s, i, i);     // Odd-length palindromes
            total += solve(s, i, i + 1); // Even-length palindromes
        }

        return total;
    }
};

