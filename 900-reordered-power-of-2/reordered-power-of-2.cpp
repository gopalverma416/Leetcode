#include <bits/stdc++.h>
using namespace std;

string countDigits(int n) {
    string s = to_string(n);
    sort(s.begin(), s.end());
    return s;
}

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        static unordered_set<string> powerSignatures;
        if (powerSignatures.empty()) {
            for (int i = 1; i <= 1e9; i <<= 1) { // generate all powers of 2
                powerSignatures.insert(countDigits(i));
            }
        }
        return powerSignatures.count(countDigits(n));
    }
};
