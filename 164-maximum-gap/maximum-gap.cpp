class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            int  prev=nums[i-1];
            int next=nums[i];
            int diff=abs(prev-next);
            maxi=max(maxi,diff);
        }
        return maxi;
    }
};