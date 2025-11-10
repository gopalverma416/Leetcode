class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = prices[0];
        int ans = 0;
        for (int i = 1; i < n; i++) {
            int val = prices[i];
            int diff = val - mini;
            if(diff>0){
              ans = max(diff, ans);
            }
          
            if (val < mini) {
                mini = val;
            }
        }
        return ans;
    }
};