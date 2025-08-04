class Solution {
    //second step coplemetd
    private:
    vector<int>parent;
    vector<int>rank;
    int findParent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findParent(parent[node]);
    }
    void unionFind(int u,int v){
        int u_parent=findParent(u);
        int v_parent=findParent(v);
        if(u_parent==v_parent){
            return;
        }
        if(rank[u_parent]>rank[v_parent]){
            parent[v_parent]=u_parent;
          rank[u]+=1;
        }else if(rank[u_parent]<rank[v_parent]){
           parent[u_parent]=v_parent;
           rank[v_parent]+=1;
        }else{
             parent[u_parent]=v_parent;
             rank[u_parent]+=1;
        }
    }
    

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
      int m=connections.size();
      if(n>m+1){
        return -1;
      }
      parent.resize(n+1);
      for(int i=0;i<n;i++){
      parent[i]=i;
      }
     //first step completed 
     
     rank.resize(n+1,1);
  for(auto it: connections){
    int u=it[0];
    int v=it[1];
    unionFind(u,v);
  }
   int component=0;
    for(int i=0;i<parent.size();i++){
        if(parent[i]==i){
           component++;
        }
    }
    return component-1;

    }
};