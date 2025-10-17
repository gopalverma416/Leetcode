class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        using P=pair<int,int>;
      
        int n=points.size();
        int conn=0;
        int total=0;
        priority_queue<P,vector<P>,greater<P>>pq;
          pq.push({0,0});
        vector<int>vis(n,-1);
        while(conn<n){
            auto [cost,u]=pq.top();
            pq.pop();
            if(vis[u]!=-1){
                continue;
            }
            vis[u]=1;
            conn++;
            total+=cost;
            for(int v=0;v<n;v++){
                if(vis[v]!=-1){
                    continue;
                }
                int dist=(abs(points[v][1]-points[u][1])+abs(points[v][0]-points[u][0]));
                pq.push({dist,v});
            }
        }
        return total;
    }
};