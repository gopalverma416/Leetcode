class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int>prefix=nums;
        int n=nums.size();
        for(int i=1;i<n;i++){
            prefix[i]+=prefix[i-1];
        }
        unordered_map<int,int>mp;
        mp[0]=1;
        int cnt=0;
        for(int i=0;i<n;i++){
            int val=prefix[i];
            int mod=val%k;
            if(mod<0){
                mod+=k;
            }
            if(mp.find(mod)!=mp.end()){
                cnt+=mp[mod];
            }
            mp[mod]++;
        }
        return cnt;
    }
};