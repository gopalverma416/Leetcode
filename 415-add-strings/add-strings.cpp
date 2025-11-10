class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        int left = n - 1;
        int right = m - 1;
        string result = "";
        int flag = 0;

        // main addition loop
        while (left >= 0 || right >= 0) {
            int ch1 = (left >= 0) ? num1[left] - '0' : 0;
            int ch2 = (right >= 0) ? num2[right] - '0' : 0;
            int sum = (ch1 + ch2 + flag) % 10;
            flag = (ch1 + ch2 + flag) / 10;
            result += (sum + '0');
            left--;
            right--;
        }

        
        if (flag) result += (flag + '0');

        reverse(result.begin(), result.end());
        return result; 
    }
};
