class Solution {
private:
    void dfs(int rw, int cl, vector<vector<int>>& heights, vector<vector<int>>& vis){
        vis[rw][cl] = 1;
        int n = heights.size();
        int m = heights[0].size();
        vector<int> hori = {-1, 0, 1, 0};
        vector<int> verti = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++){
            int nrw = rw + hori[i]; 
            int ncl = cl + verti[i]; 

            if(nrw < 0 || ncl < 0 || nrw >= n || ncl >= m) continue;

            if(heights[nrw][ncl] >= heights[rw][cl] && vis[nrw][ncl] != 1){
                dfs(nrw, ncl, heights, vis);
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> vis(n, vector<int>(m, -1)); // minimal fix: n x m
        for(int i = 0; i < m; i++){
            dfs(0, i, heights, vis);
        }
        for(int i = 0; i < n; i++){
            dfs(i, 0, heights, vis);
        }

        vector<vector<int>> vis1(n, vector<int>(m, -1)); // minimal fix: n x m
        for(int i = 0; i < m; i++){
            dfs(n-1, i, heights, vis1);
        }
        for(int i = 0; i < n; i++){
            dfs(i, m-1, heights, vis1);
        }

        vector<vector<int>> result;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis[i][j] == 1 && vis1[i][j] == 1){
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};
