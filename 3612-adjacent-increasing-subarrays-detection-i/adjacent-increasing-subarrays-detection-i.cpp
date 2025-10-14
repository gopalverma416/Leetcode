class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
       int n = nums.size();
    if (2 * k > n) return false;
    if(k==1){
        return nums.size()>=2 ?true:false;
    }

    int streak = 1;
    vector<bool> inc(n, false);

    
    for (int i = 1; i < n; i++) {
        if (nums[i] > nums[i - 1]) streak++;
        else streak = 1;

        if (streak >= k) inc[i - k + 1] = true;
    }

   
    for (int i = 0; i + 2 * k <= n; i++) {
        if (inc[i] && inc[i + k]) return true;
    }

    return false;
    }
};