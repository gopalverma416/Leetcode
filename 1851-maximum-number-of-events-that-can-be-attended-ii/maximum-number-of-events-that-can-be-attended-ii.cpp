class Solution {
private:
    vector<vector<int>> dp;

    int solve(int i, vector<vector<int>>& events, int k) {
        if (i >= events.size() || k == 0) return 0;
        if (dp[i][k] != -1) return dp[i][k];

       
        int next = upperBound(events, i);

       
        int take = events[i][2] + solve(next, events, k - 1);
       
        int skip = solve(i + 1, events, k);

        return dp[i][k] = max(take, skip);
    }

    int upperBound(vector<vector<int>>& events, int index) {
        int lo = index + 1, hi = events.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (events[mid][0] > events[index][1]) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }

public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end()); // Sort by start time
        int n = events.size();
        dp = vector<vector<int>>(n + 1, vector<int>(k + 1, -1));
        return solve(0, events, k);
    }
};
