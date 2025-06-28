class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> workers;

        for (int i = 0; i < n; ++i) {
            double ratio = (double)wage[i] / quality[i];
            workers.emplace_back(ratio, quality[i]);
        }

        sort(workers.begin(), workers.end());

        priority_queue<int> maxHeap;
        long long qualitySum = 0;
        double minCost = 1e18; 

        for (auto [ratio, q] : workers) {
            qualitySum += q;
            maxHeap.push(q);

            if (maxHeap.size() > k) {
                qualitySum -= maxHeap.top();
                maxHeap.pop();
            }

            if (maxHeap.size() == k) {
                minCost = min(minCost, ratio * qualitySum);
            }
        }

        return minCost;
    }
};
