class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<tuple<int, int, int>> q;
        int fresh = 0;

     
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j, 0}); 
                } else if (grid[i][j] == 1) {
                    fresh++;  
                }
            }
        }

        int minutes = 0;
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        
        while (!q.empty()) {
            auto [x, y, time] = q.front();
            q.pop();
            minutes = max(minutes, time);

            for (int dir = 0; dir < 4; ++dir) {
                int newX = x + dx[dir];
                int newY = y + dy[dir];

                if (newX >= 0 && newY >= 0 && newX < n && newY < m &&
                    grid[newX][newY] == 1) {
                    grid[newX][newY] = 2; 
                    fresh--;               
                    q.push({newX, newY, time + 1});
                }
            }
        }

        
        return fresh == 0 ? minutes : -1;
    }
};
