class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int val = nums[i];
            if (val == 0) {
                continue;
            } else {
                nums[idx] = nums[i];
                idx++;
            }
        }
        while(idx<n){
            nums[idx++]=0;
        }
    }
};