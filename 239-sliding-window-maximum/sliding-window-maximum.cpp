class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int n = nums.size();
        int left = 0;
        int right = 0;
        vector<int> ans;

        while (right < n) {
            int val = nums[right];

            // ❌ You were using dq.front(), should use dq.back() for comparison
            // ❌ Also dq should store indices, not values
            while (!dq.empty() && nums[dq.back()] <= val) {
                dq.pop_back();
            }
            dq.push_back(right); // ✅ store index, not value

            // ❌ Wrong condition for out-of-window element
            if (dq.front() <= right - k) {
                dq.pop_front();
            }

            // ✅ Window becomes valid only when right >= k-1
            if (right >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }

            right++;
        }
        return ans;
    }
};
