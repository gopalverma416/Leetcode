class Solution {
public:

    class DSU {
    public:
        vector<int> parent, size;

        DSU(int n) {
            parent.resize(n);
            size.resize(n, 1);
            for (int i = 0; i < n; i++) parent[i] = i;
        }

        int findPar(int u) {
            if (u == parent[u]) return u;
            return parent[u] = findPar(parent[u]);
        }

        void unite(int u, int v) {
            u = findPar(u);
            v = findPar(v);
            if (u == v) return;

            if (size[u] < size[v]) swap(u, v);
            parent[v] = u;
            size[u] += size[v];
        }
    };

    int n;

    bool isvalid(int x, int y) {
        return (x >= 0 && x < n && y >= 0 && y < n);
    }

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();

        DSU dsu(n * n);

        vector<int> dx = { -1, 0, 1, 0 };
        vector<int> dy = { 0, 1, 0, -1 };

        // Step 1 → Union all existing 1s
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {

                    int node = i * n + j;

                    for (int k = 0; k < 4; k++) {
                        int x = i + dx[k];
                        int y = j + dy[k];

                        if (isvalid(x, y) && grid[x][y] == 1) {
                            int adj = x * n + y;
                            dsu.unite(node, adj);
                        }
                    }
                }
            }
        }

        int maxi = 0;

       
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 0) {

                    unordered_set<int> st;
                    int new_area = 1;

                    for (int k = 0; k < 4; k++) {
                        int x = i + dx[k];
                        int y = j + dy[k];

                        if (isvalid(x, y) && grid[x][y] == 1) {
                            int parent = dsu.findPar(x * n + y);
                            if (!st.count(parent)) {
                                st.insert(parent);
                                new_area += dsu.size[parent];
                            }
                        }
                    }
                    maxi = max(maxi, new_area);
                }
            }
        }

        // If there was no zero at all (grid full of 1s)
        for (int i = 0; i < n * n; i++) {
            if (dsu.findPar(i) == i)
                maxi = max(maxi, dsu.size[i]);
        }

        return maxi;
    }
};
