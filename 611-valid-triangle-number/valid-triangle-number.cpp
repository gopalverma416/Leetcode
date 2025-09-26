class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        // EACH LENGTH MUST BE LESS THAN THE SUM OF OTHER TWO LENGTH. 
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int sum=nums[i]+nums[j];
                auto idx=upper_bound(nums.begin(),nums.end(),sum-1);
                int idx1=idx-nums.begin();
                 ans += max(0, idx1 - j - 1);
            }
        }
        return ans;

    }
};