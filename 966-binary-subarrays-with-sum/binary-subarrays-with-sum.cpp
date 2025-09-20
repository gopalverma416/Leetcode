class Solution {
    private:
    int lessThan(vector<int>& nums,int goal){
        if(goal<0){
            return 0;
        }
        int n=nums.size();
        int left=0;
        int right=0;
        long long cnt=0;
        long long ans=0;
        while(right<n){
         int val=nums[right];
         cnt+=val;
         while(left<=right && cnt>goal){
            int del=nums[left];
            cnt-=del;
            left++;
         }
         ans+=right-left+1;
         right++;
        }
        return (int)ans;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        return lessThan(nums,goal)-lessThan(nums,goal-1);

    }
};