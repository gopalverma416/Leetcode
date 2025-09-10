class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end(),[](vector<int>&a,vector<int>& b){
            return a[1]<b[1];
        });
        int prevInd=nums[0][1];
        int cnt=0;
        for(int i=1;i<n;i++){
         if(nums[i][0]<prevInd){
           cnt++;
         }else{
            prevInd=nums[i][1];
         }
        }
        return cnt;

    }
};