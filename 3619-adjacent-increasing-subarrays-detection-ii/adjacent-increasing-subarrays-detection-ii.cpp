class Solution {
public:
    bool solve(vector<int>& nums,int k){
        int n=nums.size();
        if(k==1){
            return true;
        }
         if (n < 2 * k) return false; 
        if(k==0){
            return true;
        }
        vector<bool>imp(n,false);
        int streak=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                streak++;
            }else{
                streak=1;
            }
            if(streak>=k){
                imp[i-k+1]=true;
            }
        }
        for(int i=0;i<n-k;i++){
            if(imp[i] && imp[i+k]){
                return true;
            }
        }
        return false;

    }
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int right=n-1;
        int ans=0;
        while(left<=right){
          int mid=(left+right)/2;
          if(solve(nums,mid)){
            ans=mid;
            left=mid+1;
          }else{
            right=mid-1;
          }
        }
        return ans;
    }
};