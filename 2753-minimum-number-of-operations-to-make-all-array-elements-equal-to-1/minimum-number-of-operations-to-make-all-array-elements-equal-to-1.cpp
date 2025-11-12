class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for (int val : nums) {
            if (val == 1) count++;
        }

        // Case 1: already have 1s
        if (count > 0) return n - count;

        // Case 2: no 1s → find shortest subarray with gcd = 1
        int operation = INT_MAX;

        for (int i = 0; i < n; i++) {
            int gc = nums[i];
            for (int j = i + 1; j < n; j++) {
                gc = __gcd(gc, nums[j]);
                if (gc == 1) {
                    operation = min(operation, j - i);
                    break; 
                }
            }
        }



        if (operation == INT_MAX) return -1;
        return operation + (n - 1);
    }
};
