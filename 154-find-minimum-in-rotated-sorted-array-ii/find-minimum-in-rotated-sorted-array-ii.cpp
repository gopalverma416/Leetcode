class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int ans = INT_MAX;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            ans = min(ans, nums[mid]);
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
             ans=min(ans,nums[left]);
             left++;
             right--;
            } else if (nums[left] <= nums[mid]) {

                ans = min(ans, nums[left]);

                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};