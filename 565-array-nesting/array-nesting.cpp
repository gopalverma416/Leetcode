 class Solution {
private:
    int dfs(int idx, vector<int>& nums, vector<int>& vis) {
        if (vis[idx]) return 0; 
        vis[idx] = 1;
        return 1 + dfs(nums[idx], nums, vis);
    }

public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<int> vis(n, 0);
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int len = dfs(i, nums, vis);
                maxi = max(maxi, len);
            }
        }
        return maxi;
    }
};
