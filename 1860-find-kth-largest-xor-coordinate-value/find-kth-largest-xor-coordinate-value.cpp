class Solution {
  public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>prefix(m,vector<int>(n,0));
        prefix[0][0]=matrix[0][0];
        for(int j=1;j<n;j++){
            prefix[0][j]=prefix[0][j-1]^matrix[0][j];
        }
        for(int i=1;i<m;i++){
            prefix[i][0]=prefix[i-1][0]^matrix[i][0];
        }
         priority_queue<int,vector<int>,greater<int>>pq;
        for (int j = 0; j < n; j++) {
            pq.push(prefix[0][j]);
            if (pq.size() > k) pq.pop();
        }
        for (int i = 1; i < m; i++) {  
            pq.push(prefix[i][0]);
            if (pq.size() > k) pq.pop();
        }

        
       
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
              prefix[i][j]=matrix[i][j]^prefix[i][j-1]^prefix[i-1][j]^prefix[i-1][j-1];
              
              pq.push(prefix[i][j]);
              if(pq.size()>k){
                pq.pop();
              }
            }
        }
        return pq.top();
    }
};