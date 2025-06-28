class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int n=nums.size();
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
        int val=nums[i];
        maxi=max(maxi,nums[i]);
        mini=min(mini,nums[i]);
        }
        for(int i=0;i<n;i++){
            int val=nums[i];
            if(val!=maxi && val!=mini){
              return val;
            }
        }
        return -1;
    }
};