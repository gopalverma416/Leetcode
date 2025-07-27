class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> adj(n + 1);

       
        adj[x].push_back(y);
        adj[y].push_back(x);

        
        for (int i = 1; i < n; i++) {
            adj[i].push_back(i + 1);
            adj[i + 1].push_back(i);
        }

        vector<int> res(n, 0);  
       
        for (int start = 1; start <= n; start++) {
            vector<int> dist(n + 1, -1);
            queue<int> q;
            q.push(start);
            dist[start] = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int nei : adj[node]) {
                    if (dist[nei] == -1) {
                        dist[nei] = dist[node] + 1;
                        q.push(nei);
                    }
                }
            }

            
            for (int j = start + 1; j <= n; j++) {
                int d = dist[j];
                if (d > 0) res[d - 1] += 2;  
            }
        }

        return res;
    }
};
