class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> aamu;
        for (int i = 0; i < n; i++) {
            aamu.push_back({nums[i], i});
        }

        sort(aamu.begin(), aamu.end());

        int start = n, end = -1;
        for (int i = 0; i < n; i++) {
            if (aamu[i].second != i) {
                start = min(start, aamu[i].second);
                end = max(end, aamu[i].second);
            }
        }

        return (end == -1) ? 0 : (end - start + 1);
    }
};