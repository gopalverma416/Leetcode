class Solution {
    private:
    int solve(vector<int>& nums,int k){
        int left=0;
        int right=0;
        int n=nums.size();
        int cnt=0;
        unordered_map<int,int>mp;
        while(right<n){
            int val=nums[right];
            mp[val]++;
            while(mp.size()>k && left<=right){
                int del=nums[left];
                mp[del]--;
                if(mp[del]==0){
                    mp.erase(del);
                }
                left++;
            }
            cnt+=right-left+1;
              right++;
        }
      
      return cnt;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
      return solve(nums,k)-solve(nums,k-1);
    }

};