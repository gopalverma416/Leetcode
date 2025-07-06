class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int cnt = 0;

        while (i < nums.size()) {
            if (nums[i] == 0) {
                nums.erase(nums.begin() + i);  
                cnt++;  
               
            } else {
                i++;
            }
        }

       
        for (int j = 0; j < cnt; j++) {
            nums.push_back(0);
        }
    }
};
