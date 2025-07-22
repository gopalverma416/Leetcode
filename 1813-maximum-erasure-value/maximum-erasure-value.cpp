class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int left=0;
        int score=0;
        int maxi=INT_MIN;
        for(int right=0;right<n;right++){
              mp[nums[right]]++;
            while(mp[nums[right]]>1){
                mp[nums[left]]--;
                score-=nums[left];
                left++;
            }
            score+=nums[right];
         maxi=max(maxi,score);
        }
        return maxi;
    }
};