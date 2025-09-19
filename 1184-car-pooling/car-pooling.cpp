class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        
        
        sort(trips.begin(), trips.end(), 
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });
        
       
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int num = trips[i][0];  
            int from = trips[i][1]; 
            int to = trips[i][2];   
            
            
            while (!pq.empty() && pq.top().first <= from) {
                cnt -= pq.top().second;
                pq.pop();
            }
            
           
            cnt += num;
            if (cnt > capacity) return false;
           
            pq.push({to, num});
        }
        return true;
    }
};
