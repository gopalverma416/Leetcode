class Solution {
    private:
    vector<int>dp;
    int solve(int i,int j,int k,vector<int>& arr){
        if(i==arr.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
      
        int take=0;
        int max_ele=0;
        for(int t=i;t<i+k && t<=j;t++){
           int ele=arr[t];
           max_ele=max(max_ele,ele);
           int ans=(t-i+1)*max_ele +solve(t+1,j,k,arr);
           take=max(take,ans);
        }
        return dp[i]= take;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        dp.resize(n+1,-1);
       return solve(0,n-1,k,arr);
    }
};