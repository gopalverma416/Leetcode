class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int cnt = 0;
        int maxi = 0;

        while (right < n) {
            int val = nums[right];
            if (val == 0) {
                cnt++;
            }
            while (cnt > 1) {
                int temp = nums[left];
                if (temp == 0) {
                    cnt--;
                }
                left++;
            }
            int len = right - left + 1;
            maxi = max(maxi, len);
            right++; 
        }
        return maxi-1;
    }
};
