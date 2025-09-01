class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& arr, int st) {
        int n = arr.size();
        vector<vector<int>> nums = arr;

        // priority queue: store {gain, index}
        priority_queue<pair<double, int>> pq;

        auto gain = [&](int up, int down) {
            return (double)(up + 1) / (down + 1) - (double)up / down;
        };

        // initialize
        for (int i = 0; i < n; i++) {
            double diff = gain(nums[i][0], nums[i][1]);
            pq.push({diff, i});
        }

        // distribute extra students
        int cnt = st;
        while (cnt-- > 0) {
            auto temp = pq.top();
            pq.pop();
            int idx = temp.second;
            nums[idx][0]++;
            nums[idx][1]++;
            double diff = gain(nums[idx][0], nums[idx][1]);
            pq.push({diff, idx});
        }

       
       
        double ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (double)nums[i][0] / nums[i][1];
        }
        return ans / n;
    }
};
