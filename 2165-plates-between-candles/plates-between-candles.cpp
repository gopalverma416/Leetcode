class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            int val = ch == '*' ? 1 : 0;
            prefix[i + 1] = prefix[i] + val;
        }

        int prev = -1;
        vector<int> previous(n, -1);
        for (int i = 0; i < n; i++) {
            if (s[i] == '|') prev = i;
            previous[i] = prev;
        }

        prev = -1;
        vector<int> next(n, -1);
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '|') prev = i;
            next[i] = prev;
        }

        int m = queries.size();
        vector<int> result;
        for (int i = 0; i < m; i++) {
            int u = queries[i][0];
            int v = queries[i][1];

            int left = next[u];     
            int right = previous[v]; // \U0001f527 should end at previous candle at/before v

            // \U0001f527 logic fix: if left/right invalid or overlapping → no plates
            if (left == -1 || right == -1 || left >= right) {
                result.push_back(0);
            } else {
                // \U0001f527 correct formula: plates between left & right = prefix[right] - prefix[left]
                result.push_back(prefix[right] - prefix[left]);
            }
        }

        return result;
    }
};
