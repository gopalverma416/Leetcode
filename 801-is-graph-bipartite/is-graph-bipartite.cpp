class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int m = graph.size();
        vector<int> vis(m, -1);
        queue<int> pq;

        for (int i = 0; i < m; i++) {
            if (vis[i] == -1) {
                pq.push(i);
                vis[i] = 1;
                while (!pq.empty()) {
                    int node = pq.front();
                    pq.pop();
                    for (auto it : graph[node]) {
                        if(it==node){
                            continue;
                        }
                        if (vis[it] == -1) {
                            vis[it] = !vis[node];
                            pq.push(it);
                        } else if (vis[it] == vis[node]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};