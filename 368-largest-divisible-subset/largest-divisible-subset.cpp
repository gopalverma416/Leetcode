class Solution {
private:
      vector<vector<vector<int>>>dp;
    vector<int> solve(int idx, vector<int>& nums, int last) {
        int n = nums.size();
        if (idx == n) {
            return {};
        }
        vector<int> best;
        if(dp[idx][last+1].size()!=0){
            return dp[idx][last+1];
        }
        for (int i = idx; i < n; i++) {
            if ( last == -1 || nums[i] % nums[last] == 0 ) {

                vector<int> curr = solve(i + 1, nums, i);
                curr.insert(curr.begin(), nums[i]);
                if (curr.size() > best.size()) {
                    best = curr;
                }
            }
        }
        return  dp[idx][last+1]=best;
    }

public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
          dp.assign(n, vector<vector<int>>(n + 1));

        return  solve(0, nums, -1);
    }
};