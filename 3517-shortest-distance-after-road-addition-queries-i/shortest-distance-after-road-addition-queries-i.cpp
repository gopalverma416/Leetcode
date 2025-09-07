class Solution {
    private:
   
 int dfs(int start, int target, vector<vector<int>>& adj, int n) {
    vector<int> dist(n, INT_MAX);
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (auto& it : adj[node]) {
            if (dist[it] > dist[node] + 1) {
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }
    return dist[target] == INT_MAX ? -1 : dist[target];
}
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>adj(n+1);
        
        for(int i=0;i<n-1;i++){
            int u=i;
            int v=i+1;
            adj[u].push_back(v);
        }
        vector<int>ans;
        for(auto& e: queries){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            int take=dfs(0,n-1,adj,n);
            ans.push_back(take);
        }
        return ans;
    }
};