#include <bits/stdc++.h>
using namespace std;

class Dsu {
    vector<int> par;
    vector<int> rank;

public:
    Dsu(int n) {
        par.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }
    int findPar(int u) {
        if (par[u] == u) return u;
        return par[u] = findPar(par[u]);
    }
    void unionByRank(int u, int v) {
        int ult_u = findPar(u);
        int ult_v = findPar(v);
        if (ult_u == ult_v) return;
        if (rank[ult_u] > rank[ult_v]) {
            par[ult_v] = ult_u;
        } else if (rank[ult_v] > rank[ult_u]) {
            par[ult_u] = ult_v;
        } else {
            par[ult_v] = ult_u;
            rank[ult_u]++;
        }
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        Dsu dsu(n);
        vector<pair<int,int>> nodes;

        for (int i = 0; i < n; i++) {
            nodes.push_back({nums[i], i});
        }
        // sort(nodes.begin(), nodes.end());

      
        for (int i = 0; i < n-1; i++) {
            int u = nodes[i].second;
            int v = nodes[i+1].second;
            int val1 = nodes[i].first;
            int val2 = nodes[i+1].first;
            if (abs(val1 - val2) <= maxDiff) {
                dsu.unionByRank(u, v);
            }
        }

        
        vector<bool> ans;
        for (auto& it : queries) {
            int u = it[0], v = it[1];
            ans.push_back(dsu.findPar(u) == dsu.findPar(v));
        }
        return ans;
    }
};
