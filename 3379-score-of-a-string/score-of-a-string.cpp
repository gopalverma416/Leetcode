class Solution {
public:
    int scoreOfString(string s) {
        int n=s.size();
        int sum=0;
        for(int i=1;i<n;i++){
            int val0=s[i-1];
            int val1=s[i];
            sum+=abs(val1-val0);
        }
        return sum;
    }
};