class myclass {
public:
    int solve(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0 && mp.find(nums[i]) == mp.end()) {
                mp[nums[i]]++;
                sum = sum + nums[i];
            }
        }
        int maxi = INT_MIN;
        if (sum == 0) {
            for (int i = 0; i < n; i++) {
                int val = nums[i];
                maxi = max(maxi, nums[i]);
            }
            return maxi;
        }
        return sum;
    }
};

class Solution {
public:
    int maxSum(vector<int>& nums) {
        myclass obj;
        int ans = obj.solve(nums);
        return ans;
    }
};
