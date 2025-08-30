class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row check
        for (int i = 0; i < 9; i++) {
            set<int> st;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '0';
                if (st.find(num) != st.end()) return false;
                st.insert(num);
            }
        }

        // column check
        for (int i = 0; i < 9; i++) {
            set<int> st;
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.') continue;
                int num = board[j][i] - '0';
                if (st.find(num) != st.end()) return false;
                st.insert(num);
            }
        }

        // 3x3 subgrid check
        for (int sr = 0; sr < 9; sr += 3) {
            for (int sc = 0; sc < 9; sc += 3) {
                set<int> st;  // <-- moved here so 1 set per subgrid
                for (int i = sr; i < sr + 3; i++) {
                    for (int j = sc; j < sc + 3; j++) {
                        if (board[i][j] == '.') continue;
                        int num = board[i][j] - '0';
                        if (st.find(num) != st.end()) return false;
                        st.insert(num);
                    }
                }
            }
        }

        return true;
    }
};
 