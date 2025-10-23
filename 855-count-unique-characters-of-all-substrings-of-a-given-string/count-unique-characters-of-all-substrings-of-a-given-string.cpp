#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size();
        vector<int> prev(n, -1), next(n, n);
        vector<int> last(26, -1);

        // Step 1: Fill prev[i]
        for (int i = 0; i < n; ++i) {
            int ch = s[i] - 'A';
            prev[i] = last[ch];
            last[ch] = i;
        }

        // Reset last to reuse
        fill(last.begin(), last.end(), n);

        // Step 2: Fill next[i]
        for (int i = n - 1; i >= 0; --i) {
            int ch = s[i] - 'A';
            next[i] = last[ch];
            last[ch] = i;
        }

        // Step 3: Calculate contribution
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += (long long)(i - prev[i]) * (next[i] - i);
        }

        return (int)ans;
    }
};
