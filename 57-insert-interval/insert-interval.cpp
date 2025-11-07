class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> result;
        int u = newInterval[0];
        int v = newInterval[1];

       
        if (n == 0) {
            result.push_back(newInterval);
            return result;
        }

        int i = 0;

      
        while (i < n && intervals[i][1] < u) {
            result.push_back(intervals[i]);
            i++;
        }

        // Case 3: merge overlapping intervals
        int first = u, second = v;
        while (i < n && intervals[i][0] <= v) {
            first = min(first, intervals[i][0]);
            second = max(second, intervals[i][1]);
            i++;
        }
        result.push_back({first, second});

        // Case 4: push the rest
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};
