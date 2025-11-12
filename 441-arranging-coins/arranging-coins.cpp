class Solution {
public:
    int arrangeCoins(int n) {
        long long N=n;
        long long row=1;
        long long sum=0;
        while(sum+row<=N){
           
          sum+=row;
          row++;
        }
        return row-1;
    }
};