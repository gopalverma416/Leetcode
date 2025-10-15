class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;

        for (int num : s) { // iterate over unique numbers
            if (!s.count(num - 1)) {
                int currentNum = num;
                int count = 1;

                while (s.count(currentNum + 1)) {
                    currentNum++;
                    count++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};
 