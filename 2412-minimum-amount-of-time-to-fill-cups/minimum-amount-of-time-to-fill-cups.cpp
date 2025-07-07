class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int>pq;
        if(amount[0]!=0){
         pq.push(amount[0]);
        }
         if(amount[1]!=0){
         pq.push(amount[1]);
         }
        
        pq.push(amount[2]);
        int cnt=0;
        while(pq.size()>=2){
         int first=pq.top();
         pq.pop();
         int second=pq.top();
         pq.pop();
         if(first>1){
          pq.push(first-1);
         }
        if(second>1){
          pq.push(second-1);
        }
        
         cnt++;
        }
       while(!pq.empty()){
        int val=pq.top();
        cnt+=val;
        pq.pop();
       }
       return cnt;
    }
};