class Solution {
public:
    int possibleStringCount(string nums) {
        int n=nums.size();
        int cnt=1;
        char prev=nums[0];
        int total=0;
        for(int i=1;i<n;i++){
            char ch=nums[i];
            if(nums[i]==nums[i-1]){
                total++;
            }
            // }else{
            //     prev=ch;
            //     if(cnt>=2){
            //    total+=cnt;
            //     }
              
            //     cnt=1;
            // }
        }
       
        return total+1;
    }
};