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

           
            while (!dq.empty() && nums[dq.back()] <= val) {
                dq.pop_back();
            }
            dq.push_back(right);

           
            if (dq.front() <= right - k) {
                dq.pop_front();
            }

           
            if (right >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }

            right++;
        }
        return ans;
    }
};
