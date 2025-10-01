class Solution {
public:
    long long maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = chargeTimes.size();
        vector<long long> prefix(n, 0);
        prefix[0] = runningCosts[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + runningCosts[i];
        }

        int left = 1, right = n;
        int ans = 0;

        while(left <= right){
            int k = left + (right-left)/2;
            if(canFit(chargeTimes, prefix, budget, k)){
                ans = k;
                left = k + 1;
            } else {
                right = k - 1;
            }
        }
        return ans;
    }

private:
    bool canFit(vector<int>& chargeTimes, vector<long long>& prefix, long long budget, int k){
        deque<int> dq;
        int n = chargeTimes.size();

        for(int i=0; i<n; i++){
        
            while(!dq.empty() && chargeTimes[dq.back()] <= chargeTimes[i])
                dq.pop_back();
            dq.push_back(i);

           
            if(dq.front() <= i-k)
                dq.pop_front();

            if(i >= k-1){
                long long sumRunning = prefix[i] - (i>=k ? prefix[i-k] : 0);
                long long totalCost = chargeTimes[dq.front()] + sumRunning * k;
                if(totalCost <= budget) return true;
            }
        }
        return false;
    }
};
