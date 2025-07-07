class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);  // 1-based index
        for (auto& t : times) {
            int u = t[0], v = t[1], w = t[2];
            adj[u].emplace_back(v, w);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, k);

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            // Skip if we've already found a better path
            if (d > dist[node]) continue;

            for (auto& [next, weight] : adj[node]) {
                if (d + weight < dist[next]) {
                    dist[next] = d + weight;
                    pq.emplace(dist[next], next);
                }
            }
        }

        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
    }
};
