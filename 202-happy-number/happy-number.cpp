class Solution {
public:
    bool isHappy(int n) {
        int total = n;
        for (int j = 0; j < 100; j++) {
            string s = to_string(total);
            int sum = 0;  // Reset sum for each iteration
            for (int i = 0; i < s.size(); i++) {
                char ch = s[i];
                int num = ch - '0';
                sum += num * num;  
            }
            total = sum;
            if (total == 1) {
                return true;
            }
        }
        return false;
    }
};
