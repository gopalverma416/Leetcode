class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size(); 
        vector<vector<int>> adj(n);

       
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int maxi = INT_MIN;

        for (int i = 0; i < n; ++i) {
            priority_queue<int> pq;

         
            for (int neighbor : adj[i]) {
                pq.push(vals[neighbor]);
            }

            int score = vals[i]; 
            int count = k;

            while (!pq.empty() && count > 0) {
                int val = pq.top(); pq.pop();
                if (val > 0) score += val;  
                count--;
            }

            maxi = max(maxi, score);
        }

        return maxi;
    }
};
