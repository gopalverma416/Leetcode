class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int ,char> mp;
        mp[1] = 'I';
        mp[5] = 'V';
        mp[10] = 'X';
        mp[50] = 'L';
        mp[100] = 'C';
        mp[500] = 'D';
        mp[1000] = 'M';
        
        string s = to_string(num);
        int len = s.length() - 1;
        string result;
        
        while (num > 0) {
            int place = pow(10, len);         // 1000, 100, 10, 1
            int div = num / place;            // digit at that place
            int rem = num % place;            // remaining number
            num = rem;                        // update number
            
            if (div == 9) {                   // 9 * place = like 9, 90, 900
                result += mp[place];
                result += mp[place * 10];
            } 
            else if (div >= 5) {              // 5..8
                result += mp[place * 5];      // Add V, L, D
                for (int i = 0; i < div - 5; i++) {
                    result += mp[place];      // Add I, X, C
                }
            } 
            else if (div == 4) {              // 4 * place
                result += mp[place];
                result += mp[place * 5];
            } 
            else {                            // 1..3
                for (int i = 0; i < div; i++) {
                    result += mp[place];
                }
            }
            
            len--; // move to next lower digit
        }
        
        return result;
    }
};
