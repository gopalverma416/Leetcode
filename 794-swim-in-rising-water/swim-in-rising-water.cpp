class Solution {
private:
    bool dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis, int t) {
        int n = grid.size();
        if (i == n - 1 && j == n - 1) return true;
        vis[i][j] = true;

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        for (int dir = 0; dir < 4; dir++) {
            int x = i + dx[dir];
            int y = j + dy[dir];
            if (x >= 0 && y >= 0 && x < n && y < n && !vis[x][y] && grid[x][y] <= t) {
                if (dfs(x, y, grid, vis, t)) return true;
            }
        }

        return false;
    }

public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int low = max(grid[0][0], grid[n-1][n-1]);
        int high = n * n - 1;
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            vector<vector<bool>> vis(n, vector<bool>(n, false));
            if (grid[0][0] <= mid && dfs(0, 0, grid, vis, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
