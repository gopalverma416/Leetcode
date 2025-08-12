class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> a_idx, b_idx;

       
        for (int i = 0; i + a.size() <= s.size(); i++) {
            if (s.substr(i, a.size()) == a) {
                a_idx.push_back(i);
            }
        }

       
        for (int i = 0; i + b.size() <= s.size(); i++) {
            if (s.substr(i, b.size()) == b) {
                b_idx.push_back(i);
            }
        }

       
        vector<int> result;
        for (int val1 : a_idx) {
            for (int val2 : b_idx) {
                if (abs(val1 - val2) <= k) {
                    result.push_back(val1); 
                    break;
                }
            }
        }
        return result;
    }
};
