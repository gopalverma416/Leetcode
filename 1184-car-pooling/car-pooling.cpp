class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n=trips.size();
        int cnt=0;
        using P=pair<int,int>;
        sort(trips.begin(),trips.end(),[](vector<int>& a,vector<int>& b){
            if(a[1]==b[1]){
                return a[2]<b[2];
            }
            return a[1]<b[1];
        });
        priority_queue<P,vector<P>,greater<P>>pq;
        for(int i=0;i<n;i++){
            int no=trips[i][0];
            int u=trips[i][1];
            int v=trips[i][2];
            while(!pq.empty() && pq.top().first<=u){
                cnt-=pq.top().second;
                pq.pop();
            }
           
            if(cnt+no>capacity){
                return false;
            }
            cnt+=no;
             pq.push({v,no});
        }
        return true;
    }
};