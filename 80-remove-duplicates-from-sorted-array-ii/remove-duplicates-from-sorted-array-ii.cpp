class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> result;
        int count = 1;
        int prev = nums[0];
        result.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            int val = nums[i];
            if (prev == val && count < 2) {
                count++;
                result.push_back(val);
            } else {
                if (val != prev) {
                    prev = val;
                    count = 1;
                    result.push_back(val);
                }
            }
        }
      for(int i=0;i<result.size();i++){
        nums[i]=result[i];
      }
        return result.size();
    }
};