class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3){
            return 0;
        }
        int count=0;
        int i=0;
        while(i+2<n){
            int diff=nums[i+1]-nums[i];
            int j=i+1;
            while(j+1<n && nums[j+1]-nums[j]==diff){
                j++;
            }
            int len=j-i+1;
            if(len>=3){
                count+=(len-2)*(len-1)/2;
            }
            i=j;
        }
        return count;
    }
};