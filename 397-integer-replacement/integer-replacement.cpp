class Solution {
public:
    int integerReplacement(int n) {
        long long N = n; // avoid overflow
        int steps = 0;
        
        while (N > 1) {
            if (N % 2 == 0) {
                N >>= 1; // divide by 2
            } else {
                if (N == 3 || ((N >> 1) & 1) == 0) {
                    N--; // go down
                } else {
                    N++; // go up
                }
            }
            steps++;
        }
        
        return steps;
    }
};
