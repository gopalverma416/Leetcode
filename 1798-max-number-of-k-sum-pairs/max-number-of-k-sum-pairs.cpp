class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = n - 1;
        int cnt = 0;

        while (left < right) { // ✅ only one loop needed
            int sum = nums[left] + nums[right];

            if (sum == k) {
                cnt++;
                left++;    
                right--;
            } 
            else if (sum > k) {
                right--;
            } 
            else { 
                left++;
            }
        }
        return cnt;
    }
};
