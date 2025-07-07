class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        priority_queue<pair<int,int>>pq;
        unordered_map<int,int>mp;
        for(auto &num: arr){
            mp[num]++;
        }
        for(auto &a : mp){
            pq.emplace(a.second,a.first);
        }
        int cnt=0;
        int total=0;
        while(!pq.empty()){
            auto [top,num]=pq.top();
            pq.pop();
         total+=top;
         cnt++;
         if(total>=n/2){
            return cnt;
         }

        }
        return -1;
    }
};