class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        int n = nums1.size();
        int m = nums2.size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        for (int i = 0; i < n && i < k; i++) {
            pq.emplace(nums1[i] + nums2[0], i, 0);
        }

        while (!pq.empty() && result.size() < k) {
            auto [sum, i, j] = pq.top(); pq.pop();
            result.emplace_back(vector<int>{nums1[i], nums2[j]}); // ✅ FIXED

            if (j + 1 < m) {
                pq.emplace(nums1[i] + nums2[j + 1], i, j + 1);
            }
        }

        return result;
    }
};

