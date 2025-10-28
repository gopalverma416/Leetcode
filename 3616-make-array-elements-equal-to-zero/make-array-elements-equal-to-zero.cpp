class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = nums[0];

        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + nums[i];

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                int left = (i > 0) ? prefix[i - 1] : 0;
                int right = (i < n - 1) ? prefix[n - 1] - prefix[i] : 0;

                if (left == right) {
                    // ✅ Even for edges, both directions are valid if all zeros
                    cnt += 2;
                } 
                else if (abs(left - right) == 1) {
                    cnt += 1;
                }
            }
        }
        return cnt;
    }
};
