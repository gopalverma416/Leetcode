#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> indeg(n, 0);
        for (int f : favorite) indeg[f]++;

        // Step 1: Topological removal to find longest chains
        queue<int> q;
        vector<int> depth(n, 1); // depth = longest chain length ending at this node
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int u = q.front(); q.pop();
            int v = favorite[u];
            depth[v] = max(depth[v], depth[u] + 1);
            if (--indeg[v] == 0) q.push(v);
        }

        // Step 2: Find cycles
        int largestCycle = 0, twoCycleSum = 0;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) {
            if (indeg[i] > 0) {
                // detect cycle length
                int cur = i, len = 0;
                while (indeg[cur] > 0) {
                    indeg[cur] = 0; // mark visited
                    cur = favorite[cur];
                    len++;
                }
                if (len == 2) {
                    // mutual favorite case
                    int a = i, b = favorite[i];
                    twoCycleSum += depth[a] + depth[b];
                } else {
                    largestCycle = max(largestCycle, len);
                }
            }
        }

        return max(largestCycle, twoCycleSum);
    }
};
