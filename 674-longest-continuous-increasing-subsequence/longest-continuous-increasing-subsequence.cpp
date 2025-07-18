class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) return 0;

        int maxLen = 1;
        int len = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                len++;
            } else {
                len = 1;
            }
            maxLen = max(maxLen, len);
        }

        return maxLen;
    }
};

