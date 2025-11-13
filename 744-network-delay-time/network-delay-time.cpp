class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n+1);
        for (auto &t : times) {
            int u = t[0], v = t[1], w = t[2];
            adj[u].push_back({v, w}); // directed + weighted
        }

        using P = pair<int,int>; // dist, node
        priority_queue<P, vector<P>, greater<P>> pq;

        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node]) continue;

            for (auto &it : adj[node]) {
                int nxt = it.first;
                int w = it.second;

                if (dist[nxt] > d + w) {
                    dist[nxt] = d + w;
                    pq.push({dist[nxt], nxt});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};
