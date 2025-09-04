#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target,
                          vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const long long INF = 1e15;
        int n = source.size();

        // Step 1: initialize distances
        vector<vector<long long>> dist(26, vector<long long>(26, INF));
        for (int i = 0; i < 26; i++) dist[i][i] = 0;

        // Step 2: add edges
        for (int i = 0; i < original.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        // Step 3: Floyd-Warshall
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        // Step 4: compute total cost
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (source[i] == target[i]) continue;
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            if (dist[u][v] == INF) return -1;
            ans += dist[u][v];
        }

        return ans;
    }
};
