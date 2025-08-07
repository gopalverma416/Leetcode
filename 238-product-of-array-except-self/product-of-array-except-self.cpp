class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product=0;
        int n=nums.size();
        vector<int>prefix(n+1,-1);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]*nums[i];
        }
        vector<int>suffix(n+1,-1);
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]*nums[i];  
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            int prev= (i-1)<0 ? 1 : prefix[i-1];
            int suff= (i+1)==n ? 1 : suffix[i+1];
            int score=prev*suff;
            ans.push_back(score);
        }
        return ans;
    }
};