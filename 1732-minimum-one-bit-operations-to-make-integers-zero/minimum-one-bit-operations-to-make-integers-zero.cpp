

class Solution {
private:
    
    int solve(int n) {
        if (n == 0) return 0;
        int highest = 1;
        while ((highest << 1) <= n) highest <<= 1;
        return (highest * 2 - 1) - solve(n ^ highest);
    }

public:
    int minimumOneBitOperations(int n) {
        return solve(n);
    }
};
