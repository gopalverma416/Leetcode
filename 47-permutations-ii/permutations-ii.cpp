class Solution {
private:
    unordered_map<int, int> map1;  // Frequency of each number in input
    unordered_map<int, int> map2;  // Frequency used in current permutation

    void solve(vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for (auto& it : map1) {
            int num = it.first;
            if (map2[num] < map1[num]) {
                temp.push_back(num);
                map2[num]++;
                solve(nums, temp, ans);
                map2[num]--;
                temp.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        for (int num : nums) {
            map1[num]++;
        }
        solve(nums, temp, ans);
        return ans;
    }
};
