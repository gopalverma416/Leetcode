class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& nums) {
        vector<int>indegree(n+1,0);
        int size=nums.size();
        if(n==1||nums.empty()){
            return true;
        }
        vector<vector<int>>adj(n);
        for(int i=0;i<size;i++){
        int u=nums[i][0];
        int v=nums[i][1];
        adj[v].push_back(u);
        }
        for(int i=0;i<size;i++){
            indegree[nums[i][0]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;
            for(auto& neighbor:adj[node]){
                indegree[neighbor]--;
                if(indegree[neighbor]==0){
                    q.push(neighbor);
                }
            }
        }
      if(cnt==n){
        return true;
      }
      return false;
    }
};