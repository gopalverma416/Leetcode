class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); 
        nums[0] = nums[0] - k; 

        for (int i = 1; i < n; i++) {
            int val = nums[i];
            int low = val - k;
            int high = val + k;
            int candidate = max(nums[i - 1] + 1, low);
            if (candidate > high) {
                nums[i] = nums[i - 1]; 
            } else {
                nums[i] = candidate;
            }
        }

        int dist = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) dist++;
        }

        return dist;
    }
};
