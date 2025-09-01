class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        unordered_map<int,vector<int>>mpr;
        unordered_map<int,vector<int>>mpc;
        for(int i=0;i<n;i++){
            mpr[i]=grid[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mpc[j].push_back(grid[i][j]);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
              
            for(int j=0;j<n;j++){
            if(mpr[i]==mpc[j]){
                cnt++;
            }
            }
        }
    return cnt;

    }
};