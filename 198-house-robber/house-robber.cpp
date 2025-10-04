class Solution {
private:
    

public:
    int rob(vector<int>& nums) {
        int idx = 0;
        int n=nums.size();
        vector<int>dp(n,-1);
         dp[n-1]=nums[n-1];
       for(int i=n-2;i>=0;i--){
        int take=nums[i];
        if(i+2<n){
         take=nums[i]+dp[i+2];
        }
        int notTake=dp[i+1];
        dp[i]=max(take,notTake);
       }
     return dp[0];
    }
};