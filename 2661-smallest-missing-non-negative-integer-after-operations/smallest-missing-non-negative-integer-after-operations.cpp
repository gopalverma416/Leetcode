class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();

       
        vector<int> freq(value, 0);
        for (int i = 0; i < n; i++) {
            int mod = ((nums[i] % value) + value) % value;
            freq[mod]++;
        }

        
        int ans = 0;
        while (true) {
            int mod = ans % value;
            if (freq[mod] == 0) return ans;
            freq[mod]--;
            ans++;
        }
        return ans;
    }
};
