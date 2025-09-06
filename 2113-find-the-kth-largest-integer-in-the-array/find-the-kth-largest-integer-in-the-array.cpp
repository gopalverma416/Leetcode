class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), [](const string &a, const string &b) {
          
            if (a.size() == b.size()) {
                return a < b; 
            }
            return a.size() < b.size(); 
        });

        int n = nums.size();
        return nums[n - k];
    }
};
