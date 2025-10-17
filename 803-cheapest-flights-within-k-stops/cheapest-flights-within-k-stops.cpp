class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> adj(n);
        int sz = flights.size();
        for (int i = 0; i < sz; i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];
            adj[u].push_back({v, wt});
        }
        using P = tuple<int, int, int>;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, src, 0});
        vector<vector<int>> dist(n + 1, vector<int>(k + 2, INT_MAX));
        while (!pq.empty()) {
            auto [step, node, stop] = pq.top();
            pq.pop();
             if (node == dst) {
                return step;
            }
            if (stop > k) {
                continue;
            }
           
            for (auto [neig, wt] : adj[node]) {
                int newSum = step + wt;
                if (newSum < dist[neig][stop + 1]) {
                    dist[neig][stop + 1] = newSum;
                    pq.push({newSum, neig, stop + 1});
                }
            }
        }
        return -1;
    }
};