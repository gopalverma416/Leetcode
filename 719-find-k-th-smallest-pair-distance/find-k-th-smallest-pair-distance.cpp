class Solution {
    private:
    int countPairs(vector<int>& nums,int mid){
      int count=0;
      int n=nums.size();
      int j=0;
      for(int i=0;i<n;i++){
        while(j<n && nums[j]-nums[i]<=mid){
            j++;
        }
        count+=j-i-1;
      }
      return count;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int left=0;
        int n=nums.size();
        int right=nums[n-1]-nums[0];
        while(left<right){
            int mid=left+(right-left)/2;
            int count=countPairs(nums,mid);
            if(count<k){
                left=mid+1;
            }else{
                
            right=mid;
            }
        }
        return left;
    }
};