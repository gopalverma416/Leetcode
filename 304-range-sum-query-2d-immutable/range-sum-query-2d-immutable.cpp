class NumMatrix {
public:
    vector<vector<int>> prefix;

    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        prefix.resize(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int up = (i > 0) ? prefix[i - 1][j] : 0;
                int left = (j > 0) ? prefix[i][j - 1] : 0;
                int diag = (i > 0 && j > 0) ? prefix[i - 1][j - 1] : 0;
                prefix[i][j] = matrix[i][j] + up + left - diag;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = prefix[row2][col2];
        int up = (row1 > 0) ? prefix[row1 - 1][col2] : 0;
        int left = (col1 > 0) ? prefix[row2][col1 - 1] : 0;
        int diag = (row1 > 0 && col1 > 0) ? prefix[row1 - 1][col1 - 1] : 0;
        return total - up - left + diag;
    }
};
