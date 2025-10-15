class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int startColor = image[sr][sc];
        
        if (startColor == color) return image; // avoid infinite loop

        queue<pair<int, int>> q;
        q.push({sr, sc});

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            image[r][c] = color;

            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && image[nr][nc] == startColor) {
                    q.push({nr, nc});
                }
            }
        }

        return image;
    }
};
