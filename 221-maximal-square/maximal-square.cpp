class Solution {
private:
    vector<int> findPrev(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> findnext(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    int findMax(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            vector<int> prevSmaller = findPrev(grid[i]);
            vector<int> nextSmaller = findnext(grid[i]);

            for (int j = 0; j < m; j++) {
                int height = grid[i][j];
                if (height == 0) continue;

                int width = nextSmaller[j] - prevSmaller[j] - 1;
                // square side can't exceed min(height, width)
                int side = min(height, width);
                int area = side * side;

                maxi = max(maxi, area);
            }
        }
        return maxi;
    }

public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> grid(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++) {
            grid[0][j] = matrix[0][j] - '0';
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    grid[i][j] = grid[i - 1][j] + 1;
                } else {
                    grid[i][j] = 0;
                }
            }
        }

        return findMax(grid);
    }
};
