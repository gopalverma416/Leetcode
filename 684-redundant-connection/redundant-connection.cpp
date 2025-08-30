#include <bits/stdc++.h>
using namespace std;

class dis {
public:
    vector<int> size, par;

    dis(int n) {
        par.resize(n + 1);
        size.resize(n + 1, 1); 
        for (int i = 1; i <= n; i++) {
            par[i] = i;
        }
    }

    int findpar(int u) {
        if (u == par[u]) return u;
        return par[u] = findpar(par[u]); 
    }

    bool unionbysize(int u, int v) {
        int ul_u = findpar(u);
        int ul_v = findpar(v);
        if (ul_u == ul_v) {
            return false; 
        }
        if (size[ul_u] < size[ul_v]) {
            swap(ul_u, ul_v);
        }
        par[ul_v] = ul_u;
        size[ul_u] += size[ul_v];
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        dis ds(n);
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            if (!ds.unionbysize(u, v)) {
                return edge; 
            }
        }
        return {};
    }
};
