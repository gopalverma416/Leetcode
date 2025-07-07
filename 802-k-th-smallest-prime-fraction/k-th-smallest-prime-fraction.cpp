class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();

        
        priority_queue<tuple<double, int, int>, vector<tuple<double, int, int>>, greater<>> pq;

     
        for (int i = 0; i < n - 1; i++) {
            pq.emplace((double)arr[i] / arr[n - 1], i, n - 1);
        }

       
        for (int cnt = 0; cnt < k - 1; cnt++) {
            auto [frac, i, j] = pq.top(); pq.pop();

            if (j - 1 > i) {
                pq.emplace((double)arr[i] / arr[j - 1], i, j - 1);
            }
        }

       
        auto [f, i, j] = pq.top();
        return {arr[i], arr[j]};
    }
};
