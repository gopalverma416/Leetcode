class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        bool hold = false;
        int purchase = prices[0];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int val = prices[i];
            if (val <= purchase) {
                purchase = val;
                hold = true;
            } else {
                ans += (val - purchase);
                purchase = val;
            }
        }
        return ans;
    }
};