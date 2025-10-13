class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        for(auto t:s){
         mp[t]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto m:mp){
            char first=m.first;
            int second=m.second;
            pq.push({second,first});
        }
        string ans;
        while(pq.size()>1){
            auto [freq1,ch1]=pq.top();
            pq.pop();
            auto [freq2,ch2]=pq.top();
            pq.pop();
            ans+=ch1;
            ans+=ch2;
            if(freq1-1>0){
                pq.push({freq1-1,ch1});
            }
            if(freq2-1>0){
                 pq.push({freq2-1,ch2});
            }
        }
        while(!pq.empty()){
            auto [frq3,ch3]=pq.top();
            pq.pop();
            if(frq3>1){
                return "";
            }else{
                ans+=ch3;
            }
        }
        return ans;
    }
};