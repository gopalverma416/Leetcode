class Solution {
private:
    // MOD removed — not needed

    vector<int> prevSmaller(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i); // ✅ added missing push
        }
        return ans;
    }

    vector<int> nextSmaller(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i]) { // ✅ strict '>' for proper counting
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i); // ✅ added missing push
        }
        return ans;
    }

    vector<int> prevGreater(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i); // ✅ added missing push
        }
        return ans;
    }

    vector<int> nextGreater(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) { // ✅ strict '<'
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i); // ✅ added missing push
        }
        return ans;
    }

public:
    long long subArrayRanges(vector<int>& nums) {
        vector<int> prevS = prevSmaller(nums);
        vector<int> nextS = nextSmaller(nums);
        vector<int> prevG = prevGreater(nums);
        vector<int> nextG = nextGreater(nums);
        int n = nums.size();
        long long score = 0;

        // For minimum contribution
        for (int i = 0; i < n; i++) {
            long long left = i - prevS[i];
            long long right = nextS[i] - i;
            score += (long long)nums[i] * left * right;
        }

        long long count = 0;

        // For maximum contribution
        for (int i = 0; i < n; i++) {
            long long left = i - prevG[i];
            long long right = nextG[i] - i;
            count += (long long)nums[i] * left * right;
        }

        return count - score;
    }
};
