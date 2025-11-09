class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> rowMax(n,0);
        vector<int> colMax(n,0);
        // for calculation of rowMax
        for(int i=0;i<n;i++){
            int maxi=INT_MIN;
            for(int j=0;j<m;j++){
                int val=grid[i][j];
                maxi=max(maxi,val);
            }
            rowMax[i]=maxi;
        }
        for(int i=0;i<n;i++){
            int maxi=INT_MIN;
            for(int j=0;j<n;j++){
               int val=grid[j][i];
               maxi=max(maxi,val);
            }
            colMax[i]=maxi;
        }
        // now toward the final ans part we will moved
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
              int tobe=min(rowMax[i],colMax[j]);
              int curr=grid[i][j];
              int diff=abs(tobe-curr);
              sum+=diff;
            }
        }
        return sum;
    }
};