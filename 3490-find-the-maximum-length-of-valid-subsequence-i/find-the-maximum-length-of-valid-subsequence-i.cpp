class Solution {
private:
   
    int dfs(int i, int prev, vector<vector<int>>& dp1, vector<int>& nums) {
        if (i == nums.size()) return 0;

        int prevParity = (prev == -1 ? -1 : prev % 2);
        if (dp1[i][prevParity + 1] != -1) return dp1[i][prevParity + 1];

        int take = 0;
        if (prev == -1 || (prev % 2 == nums[i] % 2)) {
            take = 1 + dfs(i + 1, nums[i], dp1, nums);
        }

        int skip = dfs(i + 1, prev, dp1, nums);
        return dp1[i][prevParity + 1] = max(take, skip);
    }

    int solve(int i, int prev, vector<vector<int>>& dp2, vector<int>& nums) {
        if (i == nums.size()) return 0;

        int prevParity = (prev == -1 ? -1 : prev % 2);
        if (dp2[i][prevParity + 1] != -1) return dp2[i][prevParity + 1];

        int take = 0;
        if (prev == -1 || (prev % 2 != nums[i] % 2)) {
            take = 1 + solve(i + 1, nums[i], dp2, nums);
        }

        int skip = solve(i + 1, prev, dp2, nums);
        return dp2[i][prevParity + 1] = max(take, skip);
    }

public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();

        
        vector<vector<int>> dp1(n, vector<int>(3, -1));  
        int sameParity = dfs(0, -1, dp1, nums);

       
        vector<vector<int>> dp2(n, vector<int>(3, -1));
        int alternate = solve(0, -1, dp2, nums);

        return max(sameParity, alternate);
    }
};
