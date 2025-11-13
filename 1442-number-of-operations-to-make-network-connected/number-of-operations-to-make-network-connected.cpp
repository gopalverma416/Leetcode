class Solution {
public:
    class Dsu {
        public:
        vector<int> size;
        vector<int> parent;
        Dsu(int n) {
            parent.resize(n,0);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
            size.resize(n, 1);
        }
        int findPar(int u) {
            if (u == parent[u]) {
                return u;
            }
            return parent[u] = findPar(parent[u]);
        }
        void insert(int u, int v) {
            int ult_u = findPar(u);
            int ult_v = findPar(v);
            if (size[ult_u] > size[ult_v]) {
                parent[ult_v] = ult_u;
                size[ult_u] += size[ult_v];
            } else {
                parent[ult_u] = ult_v;
                size[ult_v] += size[ult_u];
            }
        }
    };


    int makeConnected(int n, vector<vector<int>>& connections) {
        Dsu dsu(n);
        int sz = connections.size();
        for (int i = 0; i < sz; i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            int ult_u = dsu.findPar(u);
            int ult_v = dsu.findPar(v);
            if (ult_u != ult_v) {
                dsu.insert(u, v);
            }
        }
        vector<int>arr=dsu.parent;
        int need=0;
        for(int i=0;i<arr.size();i++){
          if(arr[i]==i){
            need++;
          }
        }
        need--;
        if(sz<n-1){
            return -1;
        }
        return need;
    }
};