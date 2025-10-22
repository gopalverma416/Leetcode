class Solution {
private:
    void dfs1(int node, int parent, vector<vector<int>>& adj, vector<int>& subtree_size, vector<int>& ans, int depth) {
       
        ans[0] += depth; 
        subtree_size[node] = 1;
        for (auto neig : adj[node]) {
            if (neig == parent) continue;
            dfs1(neig, node, adj, subtree_size, ans, depth + 1);
            subtree_size[node] += subtree_size[neig];
        }
    }

    void dfs2(int node, int parent, vector<vector<int>>& adj, vector<int>& subtree_size, vector<int>& ans, int n) {
        for (auto neig : adj[node]) {
            if (neig == parent) continue;
            // Re-root formula
            ans[neig] = ans[node] - subtree_size[neig] + (n - subtree_size[neig]);
            dfs2(neig, node, adj, subtree_size, ans, n);
        }
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> subtree_size(n, 0);
        vector<int> ans(n, 0);

        // Step 1: from root (0)
        dfs1(0, -1, adj, subtree_size, ans, 0);

        // Step 2: re-root and calculate for all nodes
        dfs2(0, -1, adj, subtree_size, ans, n);

        return ans;
    }
};
