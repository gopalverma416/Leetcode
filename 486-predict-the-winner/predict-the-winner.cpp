class Solution {
private:
    bool solve(int left, int right, vector<int>& nums, int Asum, int Bsum, bool turn) {
        if (left > right) {
            return Asum >= Bsum;
        }

        if (turn) { 
            bool take1 = solve(left + 1, right, nums, Asum + nums[left], Bsum, false);
            bool take2 = solve(left, right - 1, nums, Asum + nums[right], Bsum, false);
            return take1 || take2;
        } else { 
            bool take1 = solve(left + 1, right, nums, Asum, Bsum + nums[left], true);
            bool take2 = solve(left, right - 1, nums, Asum, Bsum + nums[right], true);
            return take1 && take2;  
        }
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;  
        return solve(left, right, nums, 0, 0, true);
    }
};
