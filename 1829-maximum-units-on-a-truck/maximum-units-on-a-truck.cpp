class Solution {
public:
    int maximumUnits(vector<vector<int>>& nums, int truckSize) {
        sort(nums.begin(), nums.end(),
             [](vector<int>& a, vector<int>& b) { return a[1] > b[1]; });
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int box = nums[i][0];
            int unit = nums[i][1];
            if (truckSize >= box) {
              cnt+=(box*unit);
              truckSize-=box;
            }else{
                cnt+=truckSize*unit;
                truckSize=0;
            }
        }
        return cnt;
    }
};