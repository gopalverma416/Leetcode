class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int ans = INT_MAX;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            ans = min(ans, nums[mid]);
            if (nums[l] <= nums[mid]) {
                if (nums[l] <= nums[r]) {
                    ans = min(ans, nums[l]);
                    break;
                }
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return ans;
    }
};