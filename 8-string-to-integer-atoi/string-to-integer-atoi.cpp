class Solution {
public:
    int myAtoi(string s) {
        long result=0;
        int i=0;
        int n=s.size();
        while(i<n && isspace(s[i])){
            i++;
        }
      
        int sign=1;
          if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            if (sign * result <= INT_MIN) return INT_MIN;
            if (sign * result >= INT_MAX) return INT_MAX;

            i++;
        }

       return int(sign*result);
    }
};