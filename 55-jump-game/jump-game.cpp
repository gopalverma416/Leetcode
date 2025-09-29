class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        int idx=0;
        while(idx<n && idx<=maxi){
            int val=nums[idx];
            maxi=max(maxi,val+idx);
            idx++;
        }
        if(maxi>=n-1){
            return true;
        }
        return false;
    }
};