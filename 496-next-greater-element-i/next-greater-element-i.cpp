class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;  
        int n = nums2.size();

        
        for (int i = 0; i < n; i++) {
            mp[nums2[i]] = i;
        }

        stack<int> st;
        vector<int> next(n, -1);

       
        for (int i = n - 1; i >= 0; i--) {
            int val = nums2[i];

           
            while (!st.empty() && st.top() <= val) {
                st.pop();
            }

          
            if (!st.empty()) {
                next[i] = st.top();
            }

           
            st.push(val);
        }

        
        vector<int> res(nums1.size());
        for (int i = 0; i < nums1.size(); i++) {
            int idx = mp[nums1[i]];
            res[i] = next[idx];
        }

        return res;
    }
};
