class Solution {
    private:
   bool isvalid(int x, int y, vector<vector<int>>& grid){
        int n = grid.size();
       
        for(int i = 0; i < x; i++){
            if(grid[i][y] == 1) return false;
        }
       
        int i = x - 1, j = y - 1;
        while(i >= 0 && j >= 0){
            if(grid[i][j] == 1) return false;
            i--; j--;
        }
      
        i = x - 1; j = y + 1;
        while(i >= 0 && j < n){
            if(grid[i][j] == 1) return false;
            i--; j++;
        }
        return true;
    }
    int solve(int i,int n,vector<vector<int>>& grid){
        if(i==n){
            return 1;
        }
        int take=0;
        for(int j=0;j<n;j++){
            if(isvalid(i,j,grid) && grid[i][j]==0){
                grid[i][j]=1;
                int take1=solve(i+1,n,grid);
                grid[i][j]=0;
                 take+=take1;
            }
        }
        return take;
    }
public:
    int totalNQueens(int n) {
      int size=n; 
      vector<vector<int>>grid(n,vector<int>(n,0));
     return solve(0,n,grid);
    }
};