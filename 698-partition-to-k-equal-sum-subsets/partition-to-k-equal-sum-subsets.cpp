class Solution {
private:
    bool solve(vector<int>& nums, vector<bool>& vis, int k, int start, int currSum, int target) {
       
        if (k == 1) return true;

      
        if (currSum == target)
            return solve(nums, vis, k - 1, 0, 0, target);

        int n = nums.size();
        for (int i = start; i < n; i++) {
            if (vis[i] || currSum + nums[i] > target) continue; 
            
            vis[i] = true;
            if (solve(nums, vis, k, i + 1, currSum + nums[i], target)) return true;
            vis[i] = false;
        }
        return false;
    }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for (int val : nums) sum += val;

      
        if (sum % k != 0) return false;

        int target = sum / k;
        vector<bool> vis(n, false);

      
        sort(nums.rbegin(), nums.rend());

        return solve(nums, vis, k, 0, 0, target);
    }
};
