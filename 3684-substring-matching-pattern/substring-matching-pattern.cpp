class Solution {
public:
    bool hasMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        int idx = p.find('*'); 

        string first = p.substr(0, idx);
        string second = p.substr(idx + 1);

        bool one = false, two = false;

        int idx1 = -1;
        
        for (int i = 0; i + first.size() <= n; i++) {
            if (s.substr(i, first.size()) == first) {
                idx1 = i;
                one = true;
                break;
            }
        }

       
        if (one) {
            for (int i = idx1 + first.size(); i + second.size() <= n; i++) {
                if (s.substr(i, second.size()) == second) {
                    two = true;
                    break;
                }
            }
        }

        return one && two; 
    }
};
