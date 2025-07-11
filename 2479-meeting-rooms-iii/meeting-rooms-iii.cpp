class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>busy;
        priority_queue<int,vector<int>,greater<int>>free;
       sort(meetings.begin(),meetings.end());
        vector<int>count(n+1,0);
       for(int i=0;i<n;i++){
        free.push(i);
        }
        for(int i=0;i<meetings.size();i++){
        int start=meetings[i][0];
        int end=meetings[i][1];
         while(!busy.empty() && busy.top().first <= start){
            int room=busy.top().second;
            busy.pop();
            free.push(room);
        }
        if(!free.empty()){
            int roomNo=free.top();
            free.pop();
            busy.push({end,roomNo});
            count[roomNo]++;
        }else{
            auto [freeTime,roomN]=busy.top();
            busy.pop();
            int duration=end-start;
            busy.emplace(freeTime+duration,roomN);
            count[roomN]++;
        }
        }
        int maxCount=0;
        int maxIdx=0;
        for(int i=0;i<n;i++){
            if(count[i]>maxCount){
                maxCount=max(maxCount,count[i]);
                maxIdx=i;
            }
        }
        return maxIdx;
    }
};