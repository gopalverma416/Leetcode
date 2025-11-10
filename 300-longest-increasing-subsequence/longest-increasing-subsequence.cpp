class Solution {
    private:
    vector<vector<int>>dp;
    int dfs(int idx,int last,vector<int>& nums){
        
        int n=nums.size();
        if(idx==n){
            return 0;
        }
         if(dp[idx][last+1]!=-1){
            return dp[idx][last+1];
         }
        int take=INT_MIN;
        if(last==-1 || nums[last]<nums[idx]){
           take=1+dfs(idx+1,idx,nums);
        }
        int drop=dfs(idx+1,last,nums);
        return dp[idx][last+1]= max(take,drop);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
       int n=nums.size();
       dp.resize(n,vector<int>(n+1,-1));
       return dfs(0,-1,nums); 

    }
};