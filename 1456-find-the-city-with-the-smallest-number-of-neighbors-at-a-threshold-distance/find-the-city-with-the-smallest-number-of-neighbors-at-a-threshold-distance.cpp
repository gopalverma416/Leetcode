class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int sz=edges.size();
        vector<vector<int>>dist(n,vector<int >(n,INT_MAX));
        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }
        for(int i=0;i<sz;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            dist[u][v]=wt;
            dist[v][u]=wt;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]==INT_MAX|| dist[k][j]==INT_MAX){
                        continue;
                    }
                    dist[i][j]=min(dist[i][j],(dist[i][k]+dist[k][j]));
                }
            }
        }
        int city=0;
        int cityCnt=INT_MAX;
        int cityIdx=-1;
        for(int i=0;i<n;i++){
            city=0;
            for(int j=0;j<n;j++){
                int val=dist[i][j];
                if(val<=distanceThreshold){
                    city++;
                }
            }
            if(city<=cityCnt){
               cityCnt=city;
                cityIdx=i;
            }
        }
        return cityIdx;
    }
};