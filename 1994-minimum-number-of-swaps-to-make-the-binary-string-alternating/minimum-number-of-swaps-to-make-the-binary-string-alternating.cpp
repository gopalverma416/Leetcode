class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int zero=count(s.begin(),s.end(),'0');
        int one=n-zero;
        if(abs(one-zero)>1){
            return -1;
        }
        string first = "";
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                first += '1';
            } else {
                first += '0';
            }
        }
        string second = "";
        for (int i = 0; i < n; i++) {
            if (i % 2 != 0) {
                second += '1';
            } else {
                second += '0';
            }
        }
        int cnt1 = 0;
        int cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (first[i] != s[i]) {
                cnt1++;
            }
            if (second[i] != s[i]) {
                cnt2++;
            }
        }
        
        int mini=INT_MAX;
        if(cnt1%2==0){
            mini=min(mini,cnt1/2);
        }
        if(cnt2%2==0){
            mini=min(mini,cnt2/2);
        }
        return mini;
    }
};