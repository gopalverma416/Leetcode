class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            int val=nums[i];
            if(val==0){
                continue;
            }
            if(val-ans>0){
             ans=val;
             cnt++;
            }
        }
        return cnt;
    }
};