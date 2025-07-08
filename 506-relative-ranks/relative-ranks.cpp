class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<score.size();i++){
            pq.emplace(score[i],i);
        }
        vector<string>ans(score.size());
        int cnt=1;
        while(!pq.empty()){
            auto [num,idx]=pq.top();
            pq.pop();
            if(cnt==1){
            ans[idx]="Gold Medal";
            }
           else  if(cnt==2){
                 ans[idx]="Silver Medal";
            }
            else if(cnt==3){
               
                 ans[idx]="Bronze Medal";
            }else{
                ans[idx]=to_string(cnt);
            }
            cnt++;
        }
        return ans;
    }

};