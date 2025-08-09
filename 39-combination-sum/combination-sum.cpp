class Solution {
private:
    void solve(int i, vector<int>& nums, int target, vector<int>& res, set<vector<int>>& st, int sum) {
        int n = nums.size();
        
        if (sum == target) {
            st.insert(res);
            return;
        }
        if (i == n) return;

        // take current element if it doesn't exceed target
        if (sum + nums[i] <= target) {
            res.push_back(nums[i]);
            solve(i, nums, target, res, st, sum + nums[i]);    
            solve(i + 1, nums, target, res, st, sum + nums[i]); 
            res.pop_back();
        }

       
        solve(i + 1, nums, target, res, st, sum);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;
        vector<int> res;
        solve(0, nums, target, res, st, 0);
        vector<vector<int>> result;
        result.assign(st.begin(), st.end());
        return result;
    }
};
