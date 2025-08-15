class Solution {
public:
    int integerReplacement(int n) {
        long long N = n; 
        int steps = 0;
        
        while (N > 1) {
            if (N % 2 == 0) {
                N >>= 1; 
            } else {
                if (N == 3 || ((N >> 1) & 1) == 0) {
                    N--; 
                } else {
                    N++; 
                }
            }
            steps++;
        }
        
        return steps;
    }
};
