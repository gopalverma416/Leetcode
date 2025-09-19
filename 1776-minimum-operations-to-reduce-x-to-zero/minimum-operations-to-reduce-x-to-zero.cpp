class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        //we will calculate the sum-x.  
        // array struvtite we like
        // left+(sum-x)+right=total,,(
        // we will calculate the longest continuous subarray with sum =tatal-x;
        long long total=0;
        for(int i=0;i<n;i++){
         total+=nums[i];
        }
        int left=0;
        int right=0;
        int maxi=-1;
        int target=0;
        int achive=total-x;
         if (achive < 0) return -1;
        while(right<n){
            target+=nums[right];
            
            while(left<=right && target>achive){
                target-=nums[left];
                left++;
            }
            if(target==achive){
                int len=right-left+1;
                maxi=max(maxi,len);
            }
            right++;
            
        }
        if(maxi==-1){
            return -1;
        }
        return n-maxi;
    }
};