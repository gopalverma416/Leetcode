class Solution {
private:
    void solve(int i, vector<int>& nums, int k, vector<int>& try1, set<vector<int>>& result) {
        if (try1.size() == k) {
            result.insert(try1);
            return; 
        }
        if (i >= nums.size()) return;

        
        try1.push_back(nums[i]);
        solve(i + 1, nums, k, try1, result);
        try1.pop_back();

       
        solve(i + 1, nums, k, try1, result);
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> tryi;
        set<vector<int>> result;
        vector<int> que;
        for (int i = 1; i <= n; i++) {
            que.push_back(i);
        }

        solve(0, que, k, tryi, result);

       
        vector<vector<int>> ans(result.begin(), result.end());
        return ans;
    }
};
