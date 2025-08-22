class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red=0;
        int blue=0;
        int white=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
         if(nums[i]==1){
            white++;
         }
         if(nums[i]==0){
            red++;
         }
         if(nums[i]==2){
            blue++;
         }
        }
        int idx=0;
        while(red>0){
        nums[idx]=0;
        idx++;
        red--;
        }
        while(white>0){
        nums[idx]=1;
        idx++;
        white--;
        }
         while(blue>0){
        nums[idx]=2;
        idx++;
        blue--;
        }
        
    }
};