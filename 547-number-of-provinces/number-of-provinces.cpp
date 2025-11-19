class Solution {
public:
    class Dsu {
        public:
             vector<int> par;
            vector<int> rank;
        Dsu(int n) {
           
            par.resize(n, 0);
            rank.resize(n, 1);
            for (int i = 0; i < n; i++) {
                par[i] = i;
            }
        }

        int findPar(int u) {
            if (u == par[u]) {
                return u;
            }
            return par[u] = findPar(par[u]);
        }

        void unionA(int u, int v) {
            int ult_u = findPar(u);
            int ult_v = findPar(v);
            if (rank[ult_u] > rank[ult_v]) {
                par[ult_v] = ult_u;
            } else if (rank[ult_u] < rank[ult_v]) {
                par[ult_u] = ult_v;
            } else {
                par[ult_v] = ult_u;
                rank[ult_u]++;
            }
        }
    };

    int
    findCircleNum(vector<vector<int>>& nums) {
        int n = nums.size();
        Dsu dsu(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j || nums[i][j] == 0) {
                    continue;
                }
                int ult_u = dsu.findPar(i);
                int ult_v = dsu.findPar(j);
                if (ult_u == ult_v) {
                    continue;
                }
                dsu.unionA(i, j);
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int ult_u = dsu.findPar(i);
            if (ult_u == i) {
                cnt++;
            }
        }
        return cnt;
    }
};