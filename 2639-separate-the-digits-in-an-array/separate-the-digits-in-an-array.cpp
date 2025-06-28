class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            string str = to_string(nums[i]);
            for(int idx = 0; idx < str.size(); idx++) {
                int val1 = str[idx] - '0'; 
                ans.push_back(val1);
            }
        }
        return ans;
    }
};
