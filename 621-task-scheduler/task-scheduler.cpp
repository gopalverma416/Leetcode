class Solution {
public:
    int leastInterval(vector<char>& tasks, int k) {
        int n = tasks.size();
        using P = pair<int, char>;
        priority_queue<P> pq;
        unordered_map<char, int> mp;
        
        for (char ch : tasks) mp[ch]++;
        for (auto it : mp) pq.push({it.second, it.first});
        
        int cnt = 0;
        while (!pq.empty()) {
            vector<pair<int, char>> ans;
            int time = 0; 
            
            for (int i = 0; i <= k; i++) {
                if (!pq.empty()) {
                    auto [count, ch] = pq.top();
                    pq.pop();
                    if (count > 1) ans.push_back({count - 1, ch});
                    cnt++;
                    time++;
                }
                else break; // ✅ stop early if no tasks left
            }

            for (auto &p : ans) pq.push(p);
            
            if (!pq.empty()) cnt += (k + 1 - time); // ✅ add idle time only if tasks remain
        }
        return cnt;
    }
};
