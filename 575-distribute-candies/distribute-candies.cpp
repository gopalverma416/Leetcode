class Solution {
public:
    int distributeCandies(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int cnt=1;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                cnt++;
            }
        }
         int shee=nums.size()/2;
         return min(shee,cnt);
         
    }
};