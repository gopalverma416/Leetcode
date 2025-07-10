class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> freeTime;

        freeTime.push_back(startTime[0]);

        for (int i = 1; i < n; i++) {
            freeTime.push_back(startTime[i] - endTime[i - 1]);
        }

        freeTime.push_back(eventTime - endTime[n - 1]);

        int m = freeTime.size();
        vector<int> maxRightFree(m, 0);
        vector<int> maxLeftFree(m, 0);

        for (int i = m - 2; i >= 0; i--) {
            maxRightFree[i] = max(maxRightFree[i + 1], freeTime[i + 1]);
        }

        for (int i = 1; i < m; i++) {
            maxLeftFree[i] = max(maxLeftFree[i - 1], freeTime[i - 1]);
        }

        int result = 0;
        for (int i = 1; i < m; i++) {
            int curr = endTime[i - 1] - startTime[i - 1];

            if (curr <= max(maxLeftFree[i - 1], maxRightFree[i])) {
                result = max(result, freeTime[i - 1] + curr + freeTime[i]);
            }

            result = max(result, freeTime[i - 1] + freeTime[i]);
        }

        return result;
    }
};
