class Solution {
private:
    bool isValid(vector<int>& nums, int maxSum, int k) {
        int count = 1;
        long long currentSum = 0;
        for (int num : nums) {
            if (currentSum + num > maxSum) {
                count++;
                currentSum = num;
            } else {
                currentSum += num;
            }
        }
        return count <= k;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isValid(nums, mid, k)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
};
