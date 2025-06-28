class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }

    bool isPowerOfFour(int n) {
        return isPowerOfTwo(n) && (n & 0xAAAAAAAA) == 0;
    }
};
