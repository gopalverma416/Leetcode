class Spreadsheet {
private:
    bool isOperator(char ch) {
        return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
    }

    int getOperandValue(const string& s) {
        if (s.empty()) return 0;

        if (isalpha(s[0])) { 
            int col = s[0] - 'A';
            string row_str = s.substr(1);
            if (row_str.empty()) return 0; 
            int row = stoi(row_str);
            return dp[row][col];
        } else { 
            return stoi(s);
        }
    }

public:
    vector<vector<int>> dp;

    Spreadsheet(int rows) {
        dp.resize(rows + 1, vector<int>(26, 0)); 
    }
    
    void setCell(string cell, int value) {
        char col = cell[0];
        string row = cell.substr(1);
        int col_idx = col - 'A';
        int row_idx = stoi(row);
        dp[row_idx][col_idx] = value;
    }
    
    void resetCell(string cell) {
        char col = cell[0];
        string row = cell.substr(1);
        int col_idx = col - 'A';
        int row_idx = stoi(row);
        dp[row_idx][col_idx] = 0;
    }
    
    int getValue(string formula) {
        int n = formula.size();
        int idx = -1;

    
        for (int i = 0; i < n; i++) {
            if (isOperator(formula[i])) {
                idx = i;
                break;
            }
        }

        
        if (idx == -1) {
            return getOperandValue(formula);
        }

        string left = formula.substr(1, idx);
        string right = formula.substr(idx + 1);
        char op = formula[idx];

        int num_left = getOperandValue(left);
        int num_right = getOperandValue(right);

        switch (op) {
            case '+': return num_left + num_right;
            case '-': return num_left - num_right;
            case '*': return num_left * num_right;
            case '/': return num_right != 0 ? num_left / num_right : 0;
        }
        return 0;
    }
};