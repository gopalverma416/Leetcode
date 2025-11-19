class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=INT_MAX;
        int prev=-1;
        for(int i=0;i<n;i++){
            int val=nums[i];
            if(val==1){
                if(prev==-1){
                    prev=i;
                }else{
                   int next=i;
                   int len=next-prev-1;
                   maxi=min(maxi,len);
                   prev=i;
                }
            }
        }
        if(maxi<k){
            return false;
        }
        return true;
    }
};