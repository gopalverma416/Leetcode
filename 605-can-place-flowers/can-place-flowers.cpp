class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) {
        int size = nums.size();
        
        for (int i = 0; i < size && n > 0; i++) {
            if (nums[i] == 0) {
                bool emptyLeft = (i == 0) || (nums[i - 1] == 0);
                bool emptyRight = (i == size - 1) || (nums[i + 1] == 0);
                
                if (emptyLeft && emptyRight) {
                    nums[i] = 1;
                    n--;
                }
            }
        }
        return n == 0;
    }
};
 