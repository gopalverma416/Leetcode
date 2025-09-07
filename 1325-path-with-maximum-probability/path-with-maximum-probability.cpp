class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        using P = pair<double, int>; // {probability, node}

        // Build adjacency list with probabilities
        vector<vector<pair<int,double>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];
            adj[u].push_back({v, p});
            adj[v].push_back({u, p});
        }

        // max heap (probability, node)
        priority_queue<P> pq;
        vector<double> dist(n, 0.0);

        dist[start_node] = 1.0;
        pq.push({1.0, start_node});

        while (!pq.empty()) {
            auto [prob, node] = pq.top();
            pq.pop();

            if (node == end_node) return prob; 

            for (auto& [nei, p] : adj[node]) {
                double newProb = prob * p;
                if (newProb > dist[nei]) {
                    dist[nei] = newProb;
                    pq.push({newProb, nei});
                }
            }
        }
        return 0.0;
    }
};
