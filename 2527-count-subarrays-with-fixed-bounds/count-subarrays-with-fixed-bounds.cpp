class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int left = -1;      
        int lastMin = -1;  
        int lastMax = -1;   
        long long cnt = 0;

        for (int i = 0; i < n; i++) {
            int val = nums[i];

            if (val < minK || val > maxK) {
                left = i;  
            }
            if (val == minK) lastMin = i;
            if (val == maxK) lastMax = i;

          
            cnt += max(0, min(lastMin, lastMax) - left);
        }
        return cnt;
    }
};
