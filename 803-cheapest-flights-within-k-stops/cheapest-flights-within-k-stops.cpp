class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        int sz = flights.size();
        using T = tuple<int, int, int>;
        
        // ⚠️ Added adjacency list (you forgot to build it)
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < sz; i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];
            adj[u].push_back({v, wt});   // ✅ FIXED
        }

        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({0, src, 0});

        // ⚠️ Fixed dist initialization: should be large (INF), not 0
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;

        while (!pq.empty()) {
            auto [cost, node, stop] = pq.top();  // ⚠️ renamed "dist" -> "cost" to avoid shadowing
            pq.pop();

            if (node == dst) {
                return cost;  // ✅ FIXED (was: dist[node][stop])
            }
            if (stop > k) {  // ✅ FIXED (>= to >)
                continue;
            }

            for (auto it : adj[node]) {
                int neig = it.first;
                int wei = it.second;

              
                if (cost + wei < dist[neig][stop + 1]) {
                    dist[neig][stop + 1] = cost + wei;
                    pq.push({cost + wei, neig, stop + 1});  
                }
            }
        }
        return -1;
    }
};
