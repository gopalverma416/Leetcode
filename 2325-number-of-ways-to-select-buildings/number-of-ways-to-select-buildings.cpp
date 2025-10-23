class Solution {
public:
    long long numberOfWays(string s) {
        long long zero = 0, one = 0;  
        long long zeroOne = 0, oneZero = 0; 
        long long res = 0;           
        for (char c : s) {
            if (c == '0') {
                zero++;            
                oneZero += one;   
                res += zeroOne;     
            } else {
                one++;            
                zeroOne += zero;    
                res += oneZero;     
            }
        }
        return res;
    }
};
