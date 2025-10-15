class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>mp;
        mp[nums[0]]=0;
        for(int i=1;i<n;i++){
            int val=nums[i];
            int rem=target-val;
            if(mp.count(rem)){
                return {mp[rem],i};
            }else{
            mp[val]=i;
            }
        }
        return {0,0};
    }
};