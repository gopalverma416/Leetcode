class Solution {
private:
     vector<int>ans;
    void dfs(int idx,int par, vector<vector<int>>& adj, vector<bool>& hasApple) {
        int time=0;
        for (auto it : adj[idx]) {
            if(it==par){
                continue;
            }
            dfs(it,idx,adj, hasApple);
            if(ans[it]>0 || hasApple[it]){
                ans[idx]+=ans[it]+2;
            }
        }
    }

public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        int m = edges.size();
        ans.resize(n,0);
        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0,-1,adj, hasApple);
        return ans[0];
    }
};