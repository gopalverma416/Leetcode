class Solution {
    private:
    bool canRob(vector<int>& nums,int k,int cap){
        int count=0;
        int n=nums.size();
        int i=0;
        while(i<n){
            if(nums[i]<=cap){
                count++;
                i+=2;
            }else{
                i++;
            }
        }
        return count>=k;
    }
public:
    int minCapability(vector<int>& nums, int k) {
    int left=*min_element(nums.begin(),nums.end());
    int right=*max_element(nums.begin(),nums.end());
    int ans=right;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(canRob(nums,k,mid)){
            ans=mid;
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    return ans;
    }
};