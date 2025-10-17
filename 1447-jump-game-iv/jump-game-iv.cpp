class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> mp;
        
        // Store all indices for each value in sorted order
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        using P = pair<int,int>; // {steps, index}
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});

        vector<int> dist(n, INT_MAX);
        dist[0] = 0;

        while (!pq.empty()) {
            auto [step, idx] = pq.top();
            pq.pop();

            if (idx == n-1) return step;

            // move to idx-1
            if (idx-1 >= 0 && step + 1 < dist[idx-1]) {
                dist[idx-1] = step + 1;
                pq.push({step + 1, idx-1});
            }

            // move to idx+1
            if (idx+1 < n && step + 1 < dist[idx+1]) {
                dist[idx+1] = step + 1;
                pq.push({step + 1, idx+1});
            }

            int val = arr[idx];
            auto &indices = mp[val];

           
            auto it = lower_bound(indices.begin(), indices.end(), idx);
            
           
            for (auto jt = it; jt != indices.end(); ++jt) {
                int next = *jt;
                if (step + 1 < dist[next]) {
                    dist[next] = step + 1;
                    pq.push({step + 1, next});
                }
            }

            
            for (auto jt = indices.begin(); jt != it; ++jt) {
                int next = *jt;
                if (step + 1 < dist[next]) {
                    dist[next] = step + 1;
                    pq.push({step + 1, next});
                }
            }

            
            indices.clear();
        }

        return -1;
    }
};
