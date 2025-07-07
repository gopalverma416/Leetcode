class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& f : flights) {
            adj[f[0]].emplace_back(f[1], f[2]);
        }

        // Min-heap: (cost, node, stops)
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(0, src, 0);

        // Track visited with stops
        vector<int> stopsToNode(n, INT_MAX);

        while (!pq.empty()) {
            auto [cost, u, stops] = pq.top();
            pq.pop();

            // ✅ Reached destination
            if (u == dst) return cost;

          
            if (stops > k || stops >= stopsToNode[u]) continue;

            stopsToNode[u] = stops;

            for (auto& [v, price] : adj[u]) {
                pq.emplace(cost + price, v, stops + 1);
            }
        }

        return -1;
    }
};
