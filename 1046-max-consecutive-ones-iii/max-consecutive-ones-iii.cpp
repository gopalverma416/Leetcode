class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();
        int left = 0;
        int maxi=0;
        int right=0;
        while (right < n) {
            int val = nums[right];
            if (val == 0) {
                cnt++;
            }
            while (cnt > k) {
                int del = nums[left];
                if (del == 0) {
                    cnt--;
                }
                left++;
            }
            int len=right-left+1;
            maxi=max(maxi,len);
            right++;
        }
        return maxi;
    }
};