class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        unordered_map<int, int> mp;  
        set<int> st;
        vector<int> result(n, 1);     
        for (int i = 0; i < n; i++) {
            int val = rains[i];
            if (val == 0) {
                st.insert(i);
            } else {
                result[i] = -1;
                if (mp.find(val) != mp.end()) {
                    auto it = st.lower_bound(mp[val]);
                    if (it == st.end()) {
                        return {};
                    }
                    result[*it] = val; 
                    st.erase(it);
                }
                mp[val] = i; 
            }
        }
        return result;
    }
};
