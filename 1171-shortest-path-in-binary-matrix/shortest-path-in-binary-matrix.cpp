class Solution {
public:
    vector<vector<int>> dirs = {
        {-1,-1}, {-1,0}, {-1,1}, {0,-1},
        {0,1}, {1,-1}, {1,0}, {1,1}
    };
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        if (grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;
        
        queue<tuple<int,int,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        q.push({1, 0, 0});
        vis[0][0] = 1;
        
        while (!q.empty()) {
            auto [dist, i, j] = q.front();
            q.pop();
            
            if (i == n-1 && j == m-1) return dist;
            
            for (auto& d : dirs) {
                int new_i = i + d[0];
                int new_j = j + d[1];
                
                if (new_i >= 0 && new_j >= 0 && new_i < n && new_j < m &&
                    !vis[new_i][new_j] && grid[new_i][new_j] == 0) {
                    vis[new_i][new_j] = 1;
                    q.push({dist + 1, new_i, new_j});
                }
            }
        }
        return -1;
    }
};
