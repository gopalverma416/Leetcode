class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int minProd=nums[0];
        int maxProd=nums[0];
        int maxi=nums[0];
        for(int i=1;i<n;i++){
           if(nums[i]<0){
            swap(minProd,maxProd);
           }
           minProd=min(nums[i],minProd*nums[i]);
           maxProd=max(nums[i],maxProd*nums[i]);
          maxi=max({maxi,minProd,maxProd});
        }
        return maxi;
    }
};