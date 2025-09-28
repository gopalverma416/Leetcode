class Solution {
public:
    const int MOD = 1e9+7;

    vector<int> prevSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1); // store index of prev smaller
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> nextSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, n); // store index of next smaller
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> prev = prevSmaller(arr);
        vector<int> next = nextSmaller(arr);

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;
            long long contrib = (1LL * arr[i] * left % MOD * right % MOD) % MOD;
            ans = (ans + contrib) % MOD;
        }
        return ans;
    }
};
