#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<pair<int,int>>> adj(n);
        for(auto &e : edges) {
            int u = e[0], v = e[1], time = e[2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        // dist[i][t] = min cost to reach city i in t minutes
        vector<vector<int>> dist(n, vector<int>(maxTime+1, INT_MAX));
        dist[0][0] = passingFees[0];

        // {cost, city, time} -> min-heap by cost
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({passingFees[0], 0, 0});

        while(!pq.empty()) {
            auto [cost, u, time] = pq.top(); pq.pop();

            if(u == n-1) continue; // we still explore all times <= maxTime

            if(cost > dist[u][time]) continue; // already found better

            for(auto &[v, t] : adj[u]) {
                int newTime = time + t;
                if(newTime > maxTime) continue;

                int newCost = cost + passingFees[v];
                if(newCost < dist[v][newTime]) {
                    dist[v][newTime] = newCost;
                    pq.push({newCost, v, newTime});
                }
            }
        }

        // Find minimum cost to reach city n-1 in any time <= maxTime
        int ans = INT_MAX;
        for(int t = 0; t <= maxTime; t++) ans = min(ans, dist[n-1][t]);
        return ans == INT_MAX ? -1 : ans;
    }
};

