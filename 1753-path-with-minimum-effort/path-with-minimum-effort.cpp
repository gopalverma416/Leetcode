class Solution {
    private:
    bool isvalid(int x,int y,vector<vector<int>>& heights){
        int n = heights.size();
        int m = heights[0].size();
        return (x>=0 && x<n && y>=0 && y<m);
    }

    bool solve(int x,int y,vector<vector<int>>& heights,int maxi, vector<vector<int>>& vis){
        vector<int> vert ={-1,0,1,0};
        vector<int> hori={0,1,0,-1};
        int n = heights.size();
        int m = heights[0].size();

        if(x == n-1 && y == m-1) return true;

        vis[x][y] = 1;

        for(int i=0;i<4;i++){
            int new_x = x + hori[i];
            int new_y = y + vert[i];

            if(isvalid(new_x,new_y,heights) &&
               !vis[new_x][new_y] &&
               abs(heights[new_x][new_y] - heights[x][y]) <= maxi)
            {
                if(solve(new_x,new_y,heights,maxi,vis)){
                    return true;
                }
            }
        }
        return false;
    }

public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        int low = 0, high = 1e6, ans = high;

        while(low <= high){
            int mid = (low + high) / 2;

            vector<vector<int>> vis(n, vector<int>(m, 0));

            if(solve(0,0,heights,mid,vis)){
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
