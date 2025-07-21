class Solution {
public:
    int maxJump(vector<int>& stones) {
       int n=stones.size();
       int maxi=0;
       maxi=stones[1]-stones[0];
       for(int i=2;i<n;i++){
        maxi=max(maxi,stones[i]-stones[i-2]);
       } 
       return maxi; 
    }
};