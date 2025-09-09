class Solution {
    void solve(int idx, set<int>& st, int n, int& count) {
        if (idx > n) {
            count++; 
            return;
        }

        for (int i = 1; i <= n; i++) {
            if ((idx % i == 0 || i % idx == 0) && st.find(i) == st.end()) {
                st.insert(i);
                solve(idx + 1, st, n, count);
                st.erase(i); 
            }
        }
    }

public:
    int countArrangement(int n) {
        set<int> st;
        int count = 0;
        solve(1, st, n, count);
        return count;
    }
};
