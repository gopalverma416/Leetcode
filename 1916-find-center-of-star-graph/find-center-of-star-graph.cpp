class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        int nodes = n + 1; 
        vector<int> degree(nodes + 1, 0); 

        for (auto& edge : edges) {
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        for (int i = 1; i <= nodes; i++) {
            if (degree[i] == n) return i; 
        }

        return -1;
    }
};
