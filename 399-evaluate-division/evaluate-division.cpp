class Solution {
public:
    double dfs(string src, string dst, unordered_map<string, vector<pair<string,double>>>& adj, unordered_set<string>& visited) {
        if (!adj.count(src) || !adj.count(dst)) return -1.0;
        if (src == dst) return 1.0;
        visited.insert(src);

        for (auto& [next, val] : adj[src]) {
            if (visited.count(next)) continue;
            double res = dfs(next, dst, adj, visited);
            if (res != -1.0) return val * res;
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string,double>>> adj;

        for (int i = 0; i < equations.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];

            adj[u].push_back({v, val});
            adj[v].push_back({u, 1.0 / val});
        }

        vector<double> ans;
        for (auto& q : queries) {
            string src = q[0], dst = q[1];
            unordered_set<string> visited;
            double res = dfs(src, dst, adj, visited);
            ans.push_back(res);
        }

        return ans;
    }
};
