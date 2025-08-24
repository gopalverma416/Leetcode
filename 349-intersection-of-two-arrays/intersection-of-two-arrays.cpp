class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>result;
        int n=nums1.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int val=nums1[i];
            mp[val]=1;
        }
        int m=nums2.size();
        for(int i=0;i<m;i++){
            int val=nums2[i];
            if(mp.find(nums2[i])!=mp.end()){
                result.push_back(nums2[i]);
                mp.erase(nums2[i]);
            }
        }
        return result;
    }
};