class Solution {
private:
    unordered_map<string, vector<string>> memo;

    vector<string> solve(int rem, int count) {
        if (rem == 0 && count == 0)
            return {""};

        string key = to_string(rem) + "," + to_string(count);
        if (memo.count(key)) return memo[key];

        vector<string> res;

        if (rem > 0) {
            for (string& s : solve(rem - 1, count + 1)) {
                res.push_back("(" + s);
            }
        }

        if (count > 0) {
            for (string& s : solve(rem, count - 1)) {
                res.push_back(")" + s);
            }
        }

        return memo[key] = res;
    }

public:
    vector<string> generateParenthesis(int n) {
        return solve(n, 0);
    }
};
