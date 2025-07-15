class Solution {
    private:
    void dfs(int node,vector<vector<int>>& adj,vector<bool>& seen){
        seen[node]=true;
        for(auto& neighbor : adj[node]){
            if(seen[neighbor]==false){
                dfs(neighbor,adj,seen);
            }
        }

    }
public:
    int findCircleNum(vector<vector<int>>& nums) {
        int n=nums.size();
        int cnt=0;
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
            if(nums[i][j]==1){
                adj[i].push_back(j);
            }
          }
        }
        vector<bool> seen(n,false);
    for(int i=0;i<n;i++){
        if(seen[i]==false){
         dfs(i,adj,seen);
         cnt++;
        }
    }
    return cnt;
    }
};