class Solution {
public:
    int minimumOperations(vector<int>& nums) {
       int n=nums.size();
       sort(nums.begin(),nums.end());
       int cnt=0;
        if(nums[0]>0){
            cnt++;
        }
       for(int i=1;i<n;i++){
        int val=nums[i];
       
        if(val>0 && val!=nums[i-1]){
           cnt++;
        }
       }
       return cnt;
       
    }
};