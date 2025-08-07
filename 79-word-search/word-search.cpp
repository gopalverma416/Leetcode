class Solution {
private:
    bool solve(int i, int j, int idx, vector<vector<char>>& board, string& word, vector<vector<int>>& vis) {
        if (idx == word.size() - 1) return true;

        vis[i][j] = 1;

        vector<int> hori = {-1, 0, 1, 0};
        vector<int> vert = {0, 1, 0, -1};

        for (int dir = 0; dir < 4; dir++) {
            int new_x = i + hori[dir];
            int new_y = j + vert[dir];

            if (new_x >= 0 && new_y >= 0 && new_x < board.size() && new_y < board[0].size()) {
                if (!vis[new_x][new_y] && board[new_x][new_y] == word[idx + 1]) {
                    if (solve(new_x, new_y, idx + 1, board, word, vis)) return true;
                }
            }
        }

        vis[i][j] = 0; // backtrack
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    vector<vector<int>> vis(n, vector<int>(m, 0));
                    if (solve(i, j, 0, board, word, vis)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
