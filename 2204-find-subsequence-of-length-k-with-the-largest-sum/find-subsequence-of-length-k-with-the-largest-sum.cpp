class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> arr;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            arr.push_back({nums[i], i});
        }

      
        sort(arr.begin(), arr.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        });


        vector<int> indices;
        for (int i = 0; i < k; ++i) {
            indices.push_back(arr[i].second);
        }


        sort(indices.begin(), indices.end());

      
        vector<int> result;
        for (int idx : indices) {
            result.push_back(nums[idx]);
        }

        return result;
    }
};
