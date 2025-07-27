class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int res = 0;

        for (int i = 1; i < n - 1; i++) {
            
            if (nums[i] == nums[i - 1]) continue;

            
            int left = i - 1;
            while (left >= 0 && nums[left] == nums[i]) left--;

           
            int right = i + 1;
            while (right < n && nums[right] == nums[i]) right++;

            
            if (left >= 0 && right < n) {
                if (nums[i] > nums[left] && nums[i] > nums[right]) {
                    res++;
                }
                else if (nums[i] < nums[left] && nums[i] < nums[right]) {
                    res++; 
                }
            }
        }

        return res;
    }
};
