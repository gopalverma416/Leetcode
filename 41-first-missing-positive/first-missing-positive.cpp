#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        bool containsOne = false;

      
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) containsOne = true;
            if (nums[i] <= 0 || nums[i] > n) nums[i] = 1;
        }

        if (!containsOne) return 1;

       
        for (int i = 0; i < n; i++) {
            int val = abs(nums[i]);
            if (val >= 1 && val <= n) {
                if (nums[val - 1] > 0) {
                    nums[val - 1] = -nums[val - 1];
                }
            }
        }

       
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) return i + 1;
        }

       
        return n + 1;
    }
};
