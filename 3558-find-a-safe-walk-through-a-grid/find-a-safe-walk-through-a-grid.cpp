class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        queue<tuple<int,int,int>> pq;  
        pq.push({0, 0, grid[0][0]});   

        
        vector<vector<int>> visited(n, vector<int>(m, INT_MAX));
        visited[0][0] = grid[0][0];

        vector<int> hor = {-1, 0, 1, 0};
        vector<int> ver = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto [row, col, currHe] = pq.front();
            pq.pop();

            if (row == n - 1 && col == m - 1 && currHe < health) {
                return true;
            }

            for (int dir = 0; dir < 4; dir++) {
                int newr = row + hor[dir];
                int newc = col + ver[dir];
                if (newr >= 0 && newr < n && newc >= 0 && newc < m) {
                    int newHe = currHe + grid[newr][newc];
                    if (newHe < health && newHe < visited[newr][newc]) {
                        visited[newr][newc] = newHe;
                        pq.push({newr, newc, newHe});
                    }
                }
            }
        }
        return false;
    }
};
