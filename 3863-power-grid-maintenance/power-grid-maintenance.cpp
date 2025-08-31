class Solution {
public:
   
    class DSU {
    public:
        vector<int> parent, size;
        DSU(int n) {
            parent.resize(n+1);
            size.assign(n+1, 1);
            for(int i=1; i<=n; i++) parent[i] = i;
        }
        int find(int x) {
            if(parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        }
        void unite(int a, int b) {
            a = find(a), b = find(b);
            if(a != b) {
                if(size[a] < size[b]) swap(a,b);
                parent[b] = a;
                size[a] += size[b];
            }
        }
    };
    
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU dsu(c);

        // Step 1: Build connected components
        for(auto &e: connections) {
            dsu.unite(e[0], e[1]);
        }

        // Step 2: Initialize online sets for each component
        unordered_map<int, set<int>> compOnline; 
        vector<bool> online(c+1, true);

        for(int i=1; i<=c; i++) {
            int root = dsu.find(i);
            compOnline[root].insert(i);
        }

        vector<int> ans;

        // Step 3: Process queries
        for(auto &q: queries) {
            int type = q[0], x = q[1];
            int root = dsu.find(x);

            if(type == 1) {
                if(online[x]) {
                    ans.push_back(x);
                } else {
                    if(compOnline[root].empty()) ans.push_back(-1);
                    else ans.push_back(*compOnline[root].begin());
                }
            } else { // type == 2
                if(online[x]) {
                    online[x] = false;
                    compOnline[root].erase(x);
                }
            }
        }

        return ans;
    }
};
