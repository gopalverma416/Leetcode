class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        using T = tuple<int,int,int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    pq.push({0, i, j});
                }
            }
        }

      
        if (pq.empty() || pq.size() == n * m) return -1;

        auto isValid = [&](int i, int j) {
            return (i >= 0 && i < n && j >= 0 && j < m);
        };

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

       
        while (!pq.empty()) {
            auto [d, x, y] = pq.top();
            pq.pop();
            if (dist[x][y] != INT_MAX) continue; 
            dist[x][y] = d;

            vector<int> hori = {-1, 0, 1, 0};
            vector<int> vert = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++) {
                int new_x = x + hori[i];
                int new_y = y + vert[i];
                if (isValid(new_x, new_y) && grid[new_x][new_y] == 0 && dist[new_x][new_y] == INT_MAX) {
                    pq.push({d + 1, new_x, new_y});
                }
            }
        }

        int ans = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0 && dist[i][j] != INT_MAX) {
                    ans = max(ans, dist[i][j]);
                }
            }
        }

        return ans;
    }
};
