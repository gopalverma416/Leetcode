class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string> st(deadends.begin(), deadends.end());
        using P = pair<int, string>;
        priority_queue<P, vector<P>, greater<P>> pq;
        string start = "0000";
        
        if (st.count(start)) return -1;
        
        pq.push({0, start});
        unordered_map<string, bool> mp;
        mp[start] = true;

        while (!pq.empty()) {
            auto [step, curr] = pq.top();
            pq.pop();
            
            if (curr == target) return step;

            for (int i = 0; i < 4; i++) {
                for (int d : {-1, 1}) {
                    string next = curr;
                    next[i] = ((curr[i] - '0' + d + 10) % 10) + '0';
                    if (!mp[next] && !st.count(next)) {
                        mp[next] = true;
                        pq.push({step + 1, next});
                    }
                }
            }
        }
        return -1;
    }
};
