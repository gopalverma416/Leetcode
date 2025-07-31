class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
     unordered_map<int,int>mp;
     for(auto x: nums){
        mp[x]++;
     }
     priority_queue<pair<int,int>>pq;
     for(auto it: mp){
        int count=it.second;
        int ele=it.first;
        pq.push({count,ele});
     }
     vector<int>ans;

     for(int i=0;i<k;i++){
       auto it=pq.top();
       pq.pop();
       int element=it.second;
       ans.push_back(element);
     }
     return ans;
    }
};