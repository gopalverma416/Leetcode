class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0); // degree of each city
        set<pair<int, int>> direct; // to check if two cities have direct road

        for (auto& road : roads) {
            int u = road[0], v = road[1];
            degree[u]++;
            degree[v]++;
            direct.insert({min(u, v), max(u, v)}); 
        }

        int maxRank = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                int total = degree[i] + degree[j];
                if (direct.count({i, j})) {
                    total--; 
                }
                maxRank = max(maxRank, total);
            }
        }

        return maxRank;
    }
};
