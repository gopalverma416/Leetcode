class Solution {
public:
    int maxEvents(vector<vector<int>>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); 

        priority_queue<int, vector<int>, greater<int>> pq;
        int day = nums[0][0]; 
        int i = 0;
        int count = 0;

        while (!pq.empty() || i < n) {
          
            while (i < n && nums[i][0] == day) {
                pq.push(nums[i][1]); 
                i++;
            }

            
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }

           
            if (!pq.empty()) {
                pq.pop();
                count++;
            }

            day++;
        }

        return count;
    }
};
