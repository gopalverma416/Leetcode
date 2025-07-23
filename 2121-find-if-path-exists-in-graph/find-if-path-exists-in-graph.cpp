class Solution {
    private:
    bool dfs(int node,int dest,vector<vector<int>>& adj,vector<bool>& vis){
        vis[node]=true;
        for(auto it: adj[node]){
            if(it==dest){
                return true;
            }
            if(!vis[it]){
                if(dfs(it,dest,adj,vis)){
                    return true;
                }
            }
        }
        return false;

    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination){
            return true;
        }
        vector<vector<int>>adj(n);
       for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
       }
       vector<bool>vis(n);
       return dfs(source,destination,adj,vis);

    }
};