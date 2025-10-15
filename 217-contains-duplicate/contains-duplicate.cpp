class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int val=nums[i];
            if(mp.count(val)){
                return true;
            }
            mp[val]++;
        }
        return false;
    }
};