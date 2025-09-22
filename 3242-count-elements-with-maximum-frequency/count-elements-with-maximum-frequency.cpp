class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        //map has created
        int ans=0;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            int val=nums[i];
            mp[val]++;
             maxi=max(maxi,mp[val]);
            }
        
        // we have store the frequency of all the element of the array ans also 

        // step 2 found the the elment with the max occurance 
        
        int temp=0;

        for(auto& it :mp){
            if(it.second==maxi){
                // step 3 sttore the result
                ans+=it.second;
            }
        }
        return ans;
    }
};