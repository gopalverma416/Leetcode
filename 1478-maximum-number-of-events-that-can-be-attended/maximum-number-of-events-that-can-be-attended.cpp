class Solution {
public:
    int maxEvents(vector<vector<int>>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // Sort by start day

        priority_queue<int, vector<int>, greater<int>> pq;
        int day = nums[0][0]; // Start from the first event's start day
        int i = 0;
        int count = 0;

        while (!pq.empty() || i < n) {
            // Push all events that start on the current day
            while (i < n && nums[i][0] == day) {
                pq.push(nums[i][1]); // Push end day
                i++;
            }

            // Remove expired events
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }

            // Attend one event
            if (!pq.empty()) {
                pq.pop();
                count++;
            }

            day++;
        }

        return count;
    }
};
